.section .data.Accesories
.byte 0xE  // ACC_DATA_CABLE
.byte 0xF  // ACC_USB_RS232_CABLE
.byte 0x10 // ACC_USB_CABLE
.byte 0x11 // ACC_USB_CABLE_DOWN
.byte 0x12 // ACC_USB_CABLE_N_C
.byte 0x22 // ACC_BOOT_BOX

.section .text.Jump_1
.arm
blx Hook_1

.section .text.Jump_2
.arm
blx Hook_2
