SECTIONS {
    .Common 0xA1384000 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.InitData))
        KEEP(*(.text.InitOPWV))
        KEEP(*(.text.InitWait))
        KEEP(*(.text.StartApp))
        KEEP(*(.text.StartMessenger))
    }

    .OPWV_Hooks 0xA1384140 : {
        KEEP(*(.text.OPWV_StartApp_Hook))
        KEEP(*(.text.OPWV_StartMessenger_Hook))
        KEEP(*(.text.OPWV_Destroy_Hook))
    }

    .DisableAutoLoad_Hook 0xA0944724 : {
        KEEP(*(.text.DisableAutoLoad_Hook))
    }
    .DisableAutoLoad_Jump 0xA094619E : {
        KEEP(*(.text.DisableAutoLoad_Jump))
    }

    .MoveBrowserDeviceLayerHeap 0xA06C7DD4: {
        KEEP(*(.text.MoveBrowserDeviceLayerHeap))
    }
    .BrowserDeviceLayerHeapAddr 0xA06C7EA0 : {
        KEEP(*(.data.BrowserDeviceLayerHeapAddr))
    }

    .SkipStateCheck 0xA06E7C84 : {
        KEEP(*(.text.SkipStateCheck))
    }

    .OPVW_StartApp_Trampoline 0xA05F54F8 : {
        KEEP(*(.text.OPWV_StartApp_Trampoline))
    }
    .OPWV_StartApp_Jump 0xA05FB12E : {
        KEEP(*(.text.OPWV_StartApp_Jump))
    }

    .OPWV_StartMessenger_Jump 0xa0cd6674 : {
        KEEP(*(.text.OPWV_StartMessenger_Jump))
    }

    .OPWV_Destroy_Trampoline 0xA05F551C : {
        KEEP(*(.text.OPWV_Destroy_Trampoline))
    }
    .OPWV_Destroy_Jump 0xA05FAE10 : {
        KEEP(*(.text.OPWV_Destroy_Jump))
    }
    .SkipMemHeapFreePools 0xA05FAE2A : {
        KEEP(*(.text.SkipMemHeapFreePools))
    }


    RB_OnClose_Hook 0xA1384300 : {
        KEEP(*(.text.RB_OnClose_Hook))
    }
    RB_OnClose_Jump 0xA0C514F4 : {
        KEEP(*(.data.RB_OnClose_Jump))
    }
}
