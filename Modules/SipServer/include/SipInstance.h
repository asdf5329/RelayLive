#pragma once

#ifdef SIP_EXPORTS
#define SIP_API __declspec(dllexport)
#else
#define SIP_API
#endif


class SIP_API SipInstance
{
public:
    SipInstance(void);
    ~SipInstance(void);

    static bool Init();

    static void Cleanup();

    static bool rtsp_play(string devCode, string rtpIP, int rtpPort);

    /**
     * 开启一个实时播放
     * @param[in] strDev 设备编码
     * @return true:成功 false:失败
     */
    static bool RealPlay(string strDev);

    /**
     * 关闭一个实时播放
     * @param[in] strDev 设备编码
     * @return true:成功 false:失败
     */
    static bool StopPlay(string strDev);

    /**
     * 开启一个历史视频播放
     * @param[in] strDev 设备编码
     * @param startTime 开始时间
     * @param endTime 结束时间
     * @param session 会话session
     * @return true:成功 false:失败
     */
    static bool RecordPlay(string strDev, string startTime, string endTime, string session);

    /**
     * 关闭一个实时播放
     * @param[in] strDev 设备编码
     * @param session 会话session
     * @return true:成功 false:失败
     */
    static bool StopRecordPlay(string strDev, string session);

    /**
     * 云台控制
     * @param strDev[in] 设备编码
     * @param nInOut[in]     镜头放大缩小 0:停止 1:缩小 2:放大
     * @param nUpDown[in]    镜头上移下移 0:停止 1:上移 2:下移
     * @param nLeftRight[in] 镜头左移右移 0:停止 1:左移 2:右移
     */
    static bool DeviceControl(string strDev,
        int nInOut = 0, int nUpDown = 0, int nLeftRight = 0);

private:
    static void* m_pHandle;
};

