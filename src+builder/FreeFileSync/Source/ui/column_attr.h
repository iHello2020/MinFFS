// **************************************************************************
// * This file is part of the FreeFileSync project. It is distributed under *
// * GNU General Public License: http://www.gnu.org/licenses/gpl-3.0        *
// * Copyright (C) Zenju (zenju AT gmx DOT de) - All Rights Reserved        *
// **************************************************************************
// **************************************************************************
// * This file is modified from its original source file distributed by the *
// * FreeFileSync project: http://www.freefilesync.org/ version 6.12        *
// * Modifications made by abcdec @GitHub. https://github.com/abcdec/MinFFS *
// *                          --EXPERIMENTAL--                              *
// * This program is experimental and not recommended for general use.      *
// * Please consider using the original FreeFileSync program unless there   *
// * are specific needs to use this experimental MinFFS version.            *
// *                          --EXPERIMENTAL--                              *
// * This modified program is distributed in the hope that it will be       *
// * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of *
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU       *
// * General Public License for more details.                               *
// **************************************************************************

#ifndef COL_ATTR_HEADER_189467891346732143214
#define COL_ATTR_HEADER_189467891346732143214

#include <vector>

namespace zen
{
enum ColumnTypeRim
{
    COL_TYPE_FULL_PATH,
    COL_TYPE_BASE_DIRECTORY,
    COL_TYPE_REL_FOLDER,
    COL_TYPE_FILENAME,
    COL_TYPE_SIZE,
    COL_TYPE_DATE,
    COL_TYPE_EXTENSION
};

struct ColumnAttributeRim
{
    ColumnAttributeRim() : type_(COL_TYPE_BASE_DIRECTORY), offset_(0), stretch_(0), visible_(false) {}
    ColumnAttributeRim(ColumnTypeRim type, int offset, int stretch, bool visible) : type_(type), offset_(offset), stretch_(stretch), visible_(visible) {}

    ColumnTypeRim type_;
    int           offset_;
    int           stretch_;
    bool          visible_;
};

#ifdef TODO_MinFFS_WARN_STATIC
warn_static("two stretched oclumsn: hide vergrößert range!")
#endif//TODO_MinFFS_WARN_STATIC
inline
std::vector<ColumnAttributeRim> getDefaultColumnAttributesLeft()
{
    std::vector<ColumnAttributeRim> attr;
    attr.emplace_back(COL_TYPE_FULL_PATH,      250, 0, false);
    attr.emplace_back(COL_TYPE_BASE_DIRECTORY, 200, 0, false);
    attr.emplace_back(COL_TYPE_REL_FOLDER,    -280, 1, true); //stretch to full width and substract sum of fixed size widths!
    attr.emplace_back(COL_TYPE_FILENAME,       200, 0, true);
    attr.emplace_back(COL_TYPE_DATE,           112, 0, false);
    attr.emplace_back(COL_TYPE_SIZE,            80, 0, true);
    attr.emplace_back(COL_TYPE_EXTENSION,       60, 0, false);
    return attr;
}

inline
std::vector<ColumnAttributeRim> getDefaultColumnAttributesRight()
{
    std::vector<ColumnAttributeRim> attr;
    attr.emplace_back(COL_TYPE_FULL_PATH,      250, 0, false);
    attr.emplace_back(COL_TYPE_BASE_DIRECTORY, 200, 0, false);
    attr.emplace_back(COL_TYPE_REL_FOLDER  ,  -280, 1, false); //already shown on left side
    attr.emplace_back(COL_TYPE_FILENAME,       200, 0, true);
    attr.emplace_back(COL_TYPE_DATE,           112, 0, false);
    attr.emplace_back(COL_TYPE_SIZE,            80, 0, true);
    attr.emplace_back(COL_TYPE_EXTENSION,       60, 0, false);
    return attr;
}

//------------------------------------------------------------------

enum ColumnTypeMiddle
{
    COL_TYPE_CHECKBOX,
    COL_TYPE_CMP_CATEGORY,
    COL_TYPE_SYNC_ACTION,
};

//------------------------------------------------------------------

enum ColumnTypeNavi
{
    COL_TYPE_NAVI_BYTES,
    COL_TYPE_NAVI_DIRECTORY,
    COL_TYPE_NAVI_ITEM_COUNT
};


struct ColumnAttributeNavi
{
    ColumnAttributeNavi() : type_(COL_TYPE_NAVI_DIRECTORY), offset_(0), stretch_(0), visible_(false) {}
    ColumnAttributeNavi(ColumnTypeNavi type, int offset, int stretch, bool visible) : type_(type), offset_(offset), stretch_(stretch), visible_(visible) {}

    ColumnTypeNavi type_;
    int            offset_;
    int            stretch_;
    bool           visible_;
};


const bool defaultValueShowPercentage = true;
const ColumnTypeNavi defaultValueLastSortColumn = COL_TYPE_NAVI_BYTES; //remember sort on navigation panel
const bool defaultValueLastSortAscending = false;                      //

inline
std::vector<ColumnAttributeNavi> getDefaultColumnAttributesNavi()
{
    std::vector<ColumnAttributeNavi> attr;
    attr.emplace_back(COL_TYPE_NAVI_DIRECTORY, -120, 1, true); //stretch to full width and substract sum of fixed size widths
    attr.emplace_back(COL_TYPE_NAVI_ITEM_COUNT,  60, 0, true);
    attr.emplace_back(COL_TYPE_NAVI_BYTES,       60, 0, true); //GTK needs a few pixels width more
    return attr;
}
}

#endif // COL_ATTR_HEADER_189467891346732143214
