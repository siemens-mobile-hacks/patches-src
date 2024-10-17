#!/bin/bash
set -x
set -e

cd $(dirname $0)

ACTION=$1
IAR="/opt/IAR2/common/bin/iarbuild.exe"

MODELS=( S65v58 CX70v56 SL65v53 CX75v25 SK65v50 )

if [[ $ACTION = "clean" ]]
then
	rm -rf VKP *.dep Other
else
	for model in ${MODELS[*]}; do
		wine $IAR drawhook.ewp -make $model
	done
fi
