#/bin/bash

killall -q ploybar

while pgrep -u $UID -x polybar >/dev/null; do sleep 1; done

polybar example
