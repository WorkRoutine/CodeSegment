#!/bin/bash
set -e

function Find()
{
    local _current_path
    local _parent_path
    local _name

    _current_path=$1
    if [ ${_current_path} = "/" ]; then
        _parent_path="/"
    fi



    if [ ${_current_path} != "/" -a ! -z ${_current_path} ]; then
        _parent_path=${_current_path%/*}
        if [ -z ${_parent_path} ]; then
            _parent_path="/"
        fi

        _name=${_parent_path}

        for dir in $(find $1 -type d); do
            if [ ${_name} = ${dir} ]; then
                echo "${dir}"
                exit 0
            fi
        done
    
        if [ ${_parent_path} != "/" -a ! -z ${_parent_path} ]; then
            Find ${_parent_path}  
        fi
    elif [ ${_current_path} = "/" ]; then
        _parent_path="/" 
    fi

}

Find $(pwd)
