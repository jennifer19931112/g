#pragma once

#include <vcpkg/packagespec.h>
#include <vcpkg/statusparagraphs.h>
#include <vcpkg/vcpkgcmdarguments.h>
#include <vcpkg/vcpkgpaths.h>
#include <vcpkg/versiont.h>

namespace vcpkg::Update
{
    struct OutdatedPackage
    {
        static bool compare_by_name(const OutdatedPackage& left, const OutdatedPackage& right);

        PackageSpec spec;
        VersionDiff version_diff;
    };

    std::vector<OutdatedPackage> find_outdated_packages(const std::map<std::string, VersionT>& src_names_to_versions,
                                                        const StatusParagraphs& status_db);
    void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
}