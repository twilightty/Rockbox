/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 *
 *   Copyright (C) 2020 by Dominik Riebeling
 *
 * All files in this archive are subject to the GNU General Public License.
 * See the file COPYING in the source tree root for full license agreement.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/

#ifndef PLAYERBUILDINFO_H
#define PLAYERBUILDINFO_H

#include <QSettings>

#define STATUS_RETIRED  0
#define STATUS_UNUSABLE 1
#define STATUS_UNSTABLE 2
#define STATUS_STABLE   3

// Provide information about both player and builds.
// For build info data retrieved from the build server has to be passed.
class PlayerBuildInfo : public QObject
{
public:

    enum BuildType {
        TypeRelease,
        TypeCandidate,
        TypeDaily,
        TypeDevel,
    };
    enum BuildInfo {
        BuildUrl,
        BuildVersion,
        BuildManualUrl,
        BuildVoiceUrl,
        BuildVoiceLangs,
        BuildSourceUrl,
        BuildFontUrl,

        DoomUrl,
        Duke3DUrl,
        PuzzFontsUrl,
        QuakeUrl,
        Wolf3DUrl,
        XWorldUrl,
        MidiPatchsetUrl,
    };
    enum DeviceInfo {
        BuildStatus,

        DisplayName,
        BootloaderMethod,
        BootloaderName,
        BootloaderFile,
        BootloaderFilter,
        Encoder,
        Brand,
        PlayerPicture,
    };

    enum SystemUrl {
        BootloaderUrl,
        BuildInfoUrl,
        GenlangUrl,
        ThemesUrl,
        ThemesInfoUrl,
        RbutilUrl,
    };

    static PlayerBuildInfo* instance();

    //! Update with build information from server
    void setBuildInfo(QString file);

    // Get information about a device. This data does not depend on the build type.
    QVariant value(DeviceInfo item, QString target = "");

    // Get build information for currently selected player.
    QVariant value(BuildInfo item, BuildType type);

    // Get fixed download URL information
    QVariant value(SystemUrl item);

    QString statusAsString(QString target = "");

protected:
    explicit PlayerBuildInfo();

private:
    static PlayerBuildInfo* infoInstance;
    QSettings* serverInfo;
    QSettings playerInfo;

};

#endif
