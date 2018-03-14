#!/bin/bash

#replace mail address in html file

sed -i 's/wangbin/xunweijia/g' `grep wangbin -rl ./doc`
