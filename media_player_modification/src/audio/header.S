.section .text.SetHeaderToListView_Jump
mov r0, r4
blx SetHeaderToListView

.section .text.SetHeaderToAnimationView_Jump
mov r0, r4
blx SetHeaderToAnimationView

.section .text.SetHeaderScrollText_Jump
mov r0, r4
blx SetHeaderScrollText_Hook
