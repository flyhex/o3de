/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#pragma once

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/std/containers/vector.h>
#include <AzCore/std/string/string.h>
#include <AzCore/IO/Path/Path.h>

namespace AZ
{
    class SettingsRegistryInterface;
}

namespace AzFramework
{
    //! This struct stores gem related information
    struct GemInfo
    {
        AZ_CLASS_ALLOCATOR(GemInfo, AZ::SystemAllocator, 0);
        GemInfo(AZStd::string name);
        GemInfo() = default;
        AZStd::string m_gemName; //!< A friendly display name, not to be used for any pathing stuff.
        AZStd::vector<AZ::IO::Path> m_absoluteSourcePaths; //!< Where the gem's source path folder are located(as an absolute path)

        static constexpr const char* GetGemAssetFolder() { return "Assets"; }
    };

    //! Returns a list of GemInfo of all the gems that are active for the for the specified game project. 
    //! Please note that the game project could be in a different location to the engine therefore we need the assetRoot param.
    bool GetGemsInfo(AZStd::vector<GemInfo>& gemInfoList, AZ::SettingsRegistryInterface& settingsRegistry);
}