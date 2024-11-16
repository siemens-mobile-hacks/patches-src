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

		ff="${model/v/sw}"

		if [[ -f ../elfloader3/ff/$ff.bin ]]; then
			wine postbuild/elf2vkp.exe VKP/$model/drawhook.elf VKP/$model/drawhook.vkp.tmp ../elfloader3/ff/$ff.bin
		else
			wine postbuild/elf2vkp.exe VKP/$model/drawhook.elf VKP/$model/drawhook.vkp.tmp
		fi

		cat postbuild/header.txt VKP/$model/drawhook.vkp.tmp > VKP/$model/drawhook.vkp
		rm VKP/$model/drawhook.vkp.tmp
		rm VKP/$model/drawhook.elf
	done
fi
