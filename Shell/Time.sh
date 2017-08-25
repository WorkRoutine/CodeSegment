#!/bin/bash
set -e

# This script is used to output different date

# Full show time 
date

# Display time as yymmdd 
date +%Y%m%d 

# Display 43 days ago as yymmdd 
date +%Y%m%d --date='43 days ago'

# Create a dirent with date
# mkdir `date +%Y%m%d`

# Display time and date
date +%T%n%Y%m%d

# Disply month only
date +%B%d

# Display last week/month/year/hour time
date -d "-1 week" +%Y%m%d
date -d "-1 year" +%Y%m%d
date -d "-1 month" +%Y%m%d
date -d "-1 hour" +%Y%m%d

# Full function link: [http://blog.sina.com.cn/s/blog_61c006ea0100mgxe.html]
