#!/bin/bash

uname -a | awk '{printf "#Architeture: %s\n", $0}' >> /home/monitoring.tmp
awk 'BEGIN{c=0}/physical id/{c++} END{printf "#CPU physical : %d\n", c}' /proc/cpuinfo >> /home/monitoring.tmp
awk 'BEGIN{c=0}/processor/{c++} END{printf "#vCPU : %d\n", c}' /proc/cpuinfo >> /home/monitoring.tmp
free -m | awk 'NR == 2 {printf "#Memory Usage: %d/%dMB (%.2f%%)\n", $3,$2,$3*100/$2}' >> /home/monitoring.tmp
df --total -h | awk ' /total/ {printf "#Disk Usage: %.2f/%.2fGB (%s)\n", $3, $2, $5}' >> /home/monitoring.tmp
top -bn1 | awk '/load/ {printf "#CPU Load: %.1f%%\n", $11*100}' >> /home/monitoring.tmp
who -b | awk '{printf "#Last boot: %s %s\n", $3, $4}' >> /home/monitoring.tmp
blkid | awk 'BEGIN{lvm="no"} /dev\/mapper\//{lvm="yes"} END{printf "#LVM use: %s\n", lvm}' >> /home/monitoring.tmp
ss -s | awk '/TCP:/{printf "#Connexions TCP : %d ESTABLISHED\n", $4}' >> /home/monitoring.tmp
who | awk 'BEGIN{c=0} {c++} END{printf "#User log: %d\n", c}' >> /home/monitoring.tmp
ifconfig | awk 'BEGIN{ip=0 ; mac=0} {if ($1=="inet" || $1=="ether"){if ($1=="inet" && ip==0){ip=$2}else if (mac==0){mac=$2}}} END{printf "#Network: IP %s (%s)\n", ip, mac}' >> /home/monitoring.tmp
awk 'BEGING{c=0} /COMMAND=/{c++} END{printf "#Sudo: %d cmd\n", c}' /var/log/sudo/sudo.log >> /home/monitoring.tmp
wall /home/monitoring.tmp
rm -f /home/monitoring.tmp
