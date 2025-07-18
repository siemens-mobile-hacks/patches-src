.section .text.DisableVisualizerBG
.arm
b . + 0xCC

.section .text.DrawVisualizer_Jump
.arm
blx DrawVisualizer_Hook
