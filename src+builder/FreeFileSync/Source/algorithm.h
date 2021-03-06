// **************************************************************************
// * This file is part of the FreeFileSync project. It is distributed under *
// * GNU General Public License: http://www.gnu.org/licenses/gpl-3.0        *
// * Copyright (C) Zenju (zenju AT gmx DOT de) - All Rights Reserved        *
// **************************************************************************

#ifndef ALGORITHM_H_34218518475321452548
#define ALGORITHM_H_34218518475321452548

#include <functional>
#include "file_hierarchy.h"
#include "lib/soft_filter.h"
#include "process_callback.h"


namespace zen
{
void swapGrids(const MainConfiguration& config, FolderComparison& folderCmp);

std::vector<DirectionConfig> extractDirectionCfg(const MainConfiguration& mainCfg);

void redetermineSyncDirection(const DirectionConfig& directConfig,
                              BaseFolderPair& baseFolder,
                              const std::function<void(const std::wstring& msg)>& reportWarning,
                              const std::function<void(std::int64_t bytesDelta)>& onUpdateStatus);

void redetermineSyncDirection(const MainConfiguration& mainCfg,
                              FolderComparison& folderCmp,
                              const std::function<void(const std::wstring& msg)>& reportWarning,
                              const std::function<void(std::int64_t bytesDelta)>& onUpdateStatus);

void setSyncDirectionRec(SyncDirection newDirection, FileSystemObject& fsObj); //set new direction (recursively)

bool allElementsEqual(const FolderComparison& folderCmp);

//filtering
void applyFiltering  (FolderComparison& folderCmp, const MainConfiguration& mainCfg); //full filter apply
void addHardFiltering(BaseFolderPair& baseFolder, const Zstring& excludeFilter);     //exclude additional entries only
void addSoftFiltering(BaseFolderPair& baseFolder, const SoftFilter& timeSizeFilter); //exclude additional entries only

void applyTimeSpanFilter(FolderComparison& folderCmp, std::int64_t timeFrom, std::int64_t timeTo); //overwrite current active/inactive settings

void setActiveStatus(bool newStatus, FolderComparison& folderCmp); //activate or deactivate all rows
void setActiveStatus(bool newStatus, FileSystemObject& fsObj);     //activate or deactivate row: (not recursively anymore)

std::pair<std::wstring, int> getSelectedItemsAsString( //returns string with item names and total count of selected(!) items, NOT total files/dirs!
    const std::vector<FileSystemObject*>& selectionLeft,   //all pointers need to be bound!
    const std::vector<FileSystemObject*>& selectionRight); //

//manual copy to alternate folder:
void copyToAlternateFolder(const std::vector<FileSystemObject*>& rowsToCopyOnLeft,  //all pointers need to be bound!
                           const std::vector<FileSystemObject*>& rowsToCopyOnRight, //
                           const Zstring& targetFolderPathPhrase,
                           bool keepRelPaths,
                           bool overwriteIfExists,
                           ProcessCallback& callback);

//manual deletion of files on main grid
void deleteFromGridAndHD(const std::vector<FileSystemObject*>& rowsToDeleteOnLeft,  //refresh GUI grid after deletion to remove invalid rows
                         const std::vector<FileSystemObject*>& rowsToDeleteOnRight, //all pointers need to be bound!
                         FolderComparison& folderCmp,                         //attention: rows will be physically deleted!
                         const std::vector<DirectionConfig>& directCfgs,
                         bool useRecycleBin,
                         //global warnings:
                         bool& warningRecyclerMissing,
                         ProcessCallback& callback);
}

#endif //ALGORITHM_H_34218518475321452548
