#include	"rt_config.h"


VOID Start_MCC(RTMP_ADAPTER *pAd)
{
	BSS_STRUCT *pMbss = &pAd->ApCfg.MBSSID[CFG_GO_BSSID_IDX];
	PAPCLI_STRUCT pApCliEntry = pApCliEntry = &pAd->ApCfg.ApCliTab[MAIN_MBSSID];

	struct wifi_dev *p2p_wdev = &pMbss->wdev;

	ULONG	Highpart,Lowpart;
	ULONG	NextTbtt;
	ULONG	temp;
	// 0 :STA , 1 : AP, 2 : GC, 3 : GO 
	INT role=2; //means GC role
	DBGPRINT(RT_DEBUG_ERROR,("start mcc !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"));
	/*because Start_time will channel channel 2to channel 1 , we put GO in Channel 2*/
	pAd->Mlme.bStartMcc = TRUE;

 	pAd->Mlme.channel_1st_bw = pAd->StaCfg.wdev.bw;
	if (pAd->Mlme.channel_1st_bw == HT_BW_20)
	{
		pAd->Mlme.channel_1st_primary_ch = pAd->StaCfg.wdev.channel;
		pAd->Mlme.channel_1st_center_ch = pAd->StaCfg.wdev.channel;
	}
	else
	{
		pAd->Mlme.channel_1st_primary_ch = pAd->StaCfg.wdev.channel;
		pAd->Mlme.channel_1st_center_ch = pAd->StaCfg.wdev.CentralChannel;
	}

	if (RTMP_CFG80211_VIF_P2P_GO_ON(pAd))
	{
		p2p_wdev = &pMbss->wdev;			
	 	pAd->Mlme.channel_2nd_bw = p2p_wdev->bw;
		if (pAd->Mlme.channel_2nd_bw == HT_BW_20)
		{
			pAd->Mlme.channel_2nd_primary_ch = p2p_wdev->channel;
			pAd->Mlme.channel_2nd_center_ch = p2p_wdev->channel;
		}
		else
		{
			pAd->Mlme.channel_2nd_primary_ch = p2p_wdev->channel;
			pAd->Mlme.channel_2nd_center_ch = p2p_wdev->CentralChannel;
		}
	}
	else if (RTMP_CFG80211_VIF_P2P_CLI_ON(pAd))
	{

		p2p_wdev = &pApCliEntry->wdev;
	 	pAd->Mlme.channel_2nd_bw = p2p_wdev->bw;
		if (pAd->Mlme.channel_2nd_bw == HT_BW_20)
		{
			pAd->Mlme.channel_2nd_primary_ch = p2p_wdev->channel;
			pAd->Mlme.channel_2nd_center_ch = p2p_wdev->channel;
		}
		else
		{
			pAd->Mlme.channel_2nd_primary_ch = p2p_wdev->channel;
			pAd->Mlme.channel_2nd_center_ch = p2p_wdev->CentralChannel;
		}
	}



	AsicGetTsfTime(pAd, &Highpart, &Lowpart);
	DBGPRINT(RT_DEBUG_ERROR,("!!!!Current Tsf LSB = = %ld \n",  Lowpart));

 	RTMP_IO_READ32(pAd, LPON_T1STR, &temp);
	temp = temp & 0x0000FFFF;  		
	NextTbtt	= temp % pAd->CommonCfg.BeaconPeriod; 
	DBGPRINT(RT_DEBUG_ERROR,("!!!!NextTbtt =  %ld  \n", NextTbtt));

	temp = NextTbtt*1024+Lowpart;
	DBGPRINT(RT_DEBUG_ERROR,("!!!!Tsf LSB + TimeTillTbtt= %ld \n", temp));

	pAd->cfg80211_ctrl.GONoASchedule.StartTime = Lowpart + NextTbtt*1024+ 204800 + (pAd->Mlme.channel_2nd_staytime*512);
	DBGPRINT(RT_DEBUG_ERROR,(" pAd->GONoASchedule.StartTime = %ld \n", pAd->cfg80211_ctrl.GONoASchedule.StartTime));
	pAd->cfg80211_ctrl.GONoASchedule.Duration= (pAd->Mlme.channel_1st_staytime + pAd->Mlme.switch_idle_time) *1024;
	pAd->cfg80211_ctrl.GONoASchedule.Interval=  ((pAd->Mlme.channel_2nd_staytime + pAd->Mlme.switch_idle_time) *1024) + (pAd->cfg80211_ctrl.GONoASchedule.Duration);

	/*count 200 , noa count will always 200 , not to 0*/
	pAd->cfg80211_ctrl.GONoASchedule.Count = 200; 


	if (RTMP_CFG80211_VIF_P2P_GO_ON(pAd))
	{
		role =3; //means GO
	}
	else // GC dont' care NOA start time
	{
	//	pAd->GONoASchedule.StartTime = 0 ;
	}

	CmdMccStart(pAd, pAd->Mlme.channel_1st_primary_ch, pAd->Mlme.channel_2nd_primary_ch, pAd->Mlme.channel_1st_bw,pAd->Mlme.channel_2nd_bw,
	pAd->Mlme.channel_1st_center_ch,0,pAd->Mlme.channel_2nd_center_ch,0,0,role, pAd->Mlme.channel_1st_staytime ,pAd->Mlme.channel_2nd_staytime ,
	pAd->Mlme.switch_idle_time,1,pAd->cfg80211_ctrl.GONoASchedule.StartTime);
		


}

VOID Stop_MCC(RTMP_ADAPTER *pAd,INT channel)
{
	BSS_STRUCT *pMbss = &pAd->ApCfg.MBSSID[CFG_GO_BSSID_IDX];
		PAPCLI_STRUCT pApCliEntry = pApCliEntry = &pAd->ApCfg.ApCliTab[MAIN_MBSSID];
		struct wifi_dev *p2p_wdev = &pMbss->wdev;

		pAd->Mlme.bStartMcc = FALSE;

		printk("Stop_MCC swtich to channel %d \n",channel);
		CmdMccStop(pAd, channel, 0, 0, 0); //park at p2p GO| CLI Cannel
#if 0
		if (channel == 1 )
		{
			AsicSwitchChannel(pAd, pAd->StaCfg.wdev.CentralChannel, FALSE);
			bbp_set_bw(pAd, pAd->StaCfg.wdev.bw);
		}
		else if(channel == 2 )
		{
			if (RTMP_CFG80211_VIF_P2P_GO_ON(pAd))
				p2p_wdev = &pMbss->wdev;	
			else if (RTMP_CFG80211_VIF_P2P_CLI_ON(pAd))
				p2p_wdev = &(pApCliEntry->wdev);


			AsicSwitchChannel(pAd, p2p_wdev->CentralChannel, FALSE);
			bbp_set_bw(pAd, p2p_wdev->bw);

		}
		else
		{
			AsicSwitchChannel(pAd, pAd->StaCfg.wdev.CentralChannel, FALSE);
			bbp_set_bw(pAd, pAd->StaCfg.wdev.bw);
		}
#endif

}
