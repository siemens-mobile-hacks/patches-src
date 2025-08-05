#!/bin/bash
set -x
set -e

cd $(dirname $0)

ACTION=$1
IAR="/opt/IAR2/common/bin/iarbuild.exe"

MODELS=( CX75sw25 )

if [[ $ACTION = "clean" ]]
then
	rm -rf VKP *.dep Other
else
	for model in ${MODELS[*]}; do
		wine $IAR eheap.ewp -make $model

		ff="${model/v/sw}"

		if [[ -f ../../elfloader3/ff/$ff.bin ]]; then
			wine postbuild/elf2vkp.exe VKP/$model/eheap.elf VKP/$model/eheap.vkp.tmp ../../elfloader3/ff/$ff.bin
		else
			wine postbuild/elf2vkp.exe VKP/$model/eheap.elf VKP/$model/eheap.vkp.tmp
		fi

		cat postbuild/header.txt VKP/$model/eheap.vkp.tmp > VKP/$model/eheap.vkp
		rm VKP/$model/eheap.vkp.tmp
		rm VKP/$model/eheap.elf
	done
fi
