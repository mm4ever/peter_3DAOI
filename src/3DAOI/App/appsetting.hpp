#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <iostream>

#include <QSettings>
#include <QFile>
#include <QMetaEnum>

#include "../SDK/customexception.hpp"

/*
std::string MachineName[2] = {"AOI","SPI"};
std::string Theme[2] = {"BLACK","WHITE"};
std::string Lane[2] = {"EN","CN"};
std::string LaneMode[3] = {"SIMULATOR","SINGLELANE","DUALLANE"};
*/

namespace App
{
    /**
     *  @brief AppSetting
     *
     *  @author peter
     *  @version 1.00 2017-11-22 peter
     *                note:create it
     */
    class AppSetting
    {
    public:
//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // constructor & destructor
        /**
         * @brief AppSetting
         *      构造函数
         * @param N/A
         * @return N/A
         */
        AppSetting();
        /**
         * @brief ~CaptureSetting
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual ~AppSetting();
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // load function
        /**
         *  @brief loadAppSetting
         *      加载配置文件
         *  @param path
         *      待加载的配置文件路径
         *  @return N/A
         */
        void loadAppSetting(const QString& path);
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_companyName;
        enum MachineName {AOI,SPI}m_machineName;
        enum Theme {BLACK,WHITE}m_theme;
        enum Lang {EN,CN}m_lang;
        enum LaneMode {SIMULATOR,SINGLELANE,DUALLANE}m_laneMode;

        /**
         *  @brief readCaptureSetting
         *      读取配置文件中的信息(配置文件存在)
         *  @param path
         *      待读取的配置文件路径
         *  @return N/A
         */
        void readAppSetting( const QString& path );
        /**
         *  @brief readCaptureSetting
         *      写入配置信息到文件中(配置文件不存在存在)
         *  @param path
         *      待写入的配置文件路径
         *  @return N/A
         */
        void writeAppSetting( const QString& path );

    };

}//End of App

#endif //APPSETTING_HPP













