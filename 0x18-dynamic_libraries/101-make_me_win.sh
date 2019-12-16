#!/bin/bash
wget -qO /tmp/jackpot.so https://github.com/jzamora5/holbertonschool-low_level_programming/raw/master/0x18-dynamic_libraries/jackpot.so
export LD_PRELOAD=/tmp/jackpot.so
