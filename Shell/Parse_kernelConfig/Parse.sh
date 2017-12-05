#!/bin/bash

#
# Delete empty line and note on .config
#
# (C) 2017.12 <buddyzhang@aliyun.com>
#

INPUT_CONFIG=.config
OUTPUT_CONFIG=kernel_config

cat ${INPUT_CONFIG} | grep -v "^\s*#.*" | grep -v '^\s*$' | awk '{print $$0}' | sort > ${OUTPUT_CONFIG}
