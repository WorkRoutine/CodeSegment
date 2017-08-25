#!/bin/bash
# ----------------------------------------------
# Version Control
# Maintain different project
# Maintainer: Buddy <buddy.zhang@aliyun.com>
#
set -e

# Parepare
#. lib/Prepare

# Import Envirnoment
. lib/Import_Envirnoment

# Initialize Project
. lib/PROJECT_INIT

# Import function
. lib/FUNCTION

# Main Menu
echo "=== System ==="
echo "0. Create a new project"
echo "1. Delete a project"
echo "2. Backup new file/dirent"
echo "3. Delet file/dirent"
echo "4. Exchange project"
read OPTION

if [ ${OPTION} = "0" ]; then
    . ${ROOT}/lib/Cread_New_Project
    . ${ROOT}/lib/HISTORY_NOTE
    exit 0
elif [ ${OPTION} = "1" ]; then
    . ${ROOT}/lib/Delete_A_Project
    . ${ROOT}/lib/HISTORY_NOTE
    exit 0
elif [ ${OPTION} = "2" ]; then
    . ${ROOT}/lib/BACKUP_FILE_DIRENT
    . ${ROOT}/lib/HISTORY_NOTE
    exit 0
elif [ ${OPTION} = "3" ]; then
    . ${ROOT}/lib/HISTORY_NOTE
    exit 0
elif [ ${OPTION} = "4" ]; then
    echo ""
else
    echo "Pls input correct value!"
fi

. ${ROOT}/lib/DO_EXCHANGE
