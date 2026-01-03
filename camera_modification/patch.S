#ifdef E71_45
    .equ GeneralFuncF1, 0xA07F8F6C
#endif

.section .text.SetResolutionString_Jump
.arm
blx SetResolutionString_Hook

.section .text.StartViewFinder_Jump
.arm
mov r0, r4
blx StartViewFinder_Hook

.section .text.SkipSetPosition_Part1
.arm
nop

.section .text.SkipSetPosition_Part2
.arm
nop

.section .text.FixStoreCoordinates_Jump
.arm
add r0, sp, #0x70
add r1, sp, #0x68
add r2, sp, #0x78
blx FixStoreCoordinates_Hook
b . + 0x38

.section .data.ChangePhotoResolution_1
.short 640
.short 480

.section .data.ChangePhotoResolution_2
.short 1024
.short 768

.section .data.ChangePhotoResolution_3
.short 1280
.short 720

.section .data.FixHeaderText
.int 0x1C60

.section .text.SetHeaderLgp_Jump
.arm
moveq r0, r4
bleq SetHeaderLgp_Hook

.section .text.OnRedraw_Jump
.arm
blx OnRedraw_Hook

.section .text.DisableZoomIcons
.arm
b . + 0xD4

.section .text.DisableRemainingPhotos
.arm
b . + 0xDC

.section .text.ChangeInfoTextColor_Part1
.arm
mov r0, #0x1

.section .text.ChangeInfoTextColor_Part2
.arm
mov r0, #0x00

.section .text.DisableSelfTimer
.arm
mov r0, #0x00

.section .text.DisableMessageSavedTo
.arm
b . + 0x2C8

.section .text.ChangeFileName_Jump
.arm
blx ChangeFileName_Hook

.section .text.Options_DisableMessages
.arm
mov r0, #0x1
bl GeneralFuncF1
mov r0, #0x00

.section .text.Options_Active_RemoveItemHelp_Part1
.arm
nop

.section .text.Options_Active_RemoveItemHelp_Part2
.arm
mov r1, #0x9

.section .data.Options_Idle_FixItemPictures
.int 0x81B

.section .data.Options_Idle_FixItemOtherVideos
.int 0x81B

.section .data.Options_Idle_RemoveItemHelp
.int 0x55C

.section .text.Settings_RemoveItemDefaultName
.arm
mov r7, #0x00
b . + 0x118

.section .text.Settings_SetResolution_Jump
.arm
ldr r0, [r4, #0x28]
mov r1, r8
mov r2, r7
sub r2, r2, #0x01
blx Settings_SetResolution_Hook
b . + 0x8
