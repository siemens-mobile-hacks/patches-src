SECTIONS {
    .FindCSM 0xA1382D00 : {
        KEEP(*(.text.FindCSM));
    }

    .CallRecords_Fix_Part1 0xA0B20BB0 : {
        KEEP(*(.text.CallRecords_Fix_Part1))
    }
    .CallRecords_Fix_Part2 0xA0B20B88 : {
        KEEP(*(.text.CallRecords_Fix_Part2))
    }

    .CallRecords_Delete_DisableMessage_AllEntriesDelete 0xA09A288A : {
        KEEP(*(.text.CallRecords_Delete_DisableMessage_AllEntriesDelete))
    }
    .CallRecords_Delete_DisableMessage_EntryDeleted 0xA09A289A : {
        KEEP(*(.text.CallRecords_Delete_DisableMessage_EntryDeleted))
    }
    .CallRecords_Delete_DisableMessage_CannotBeDeleted 0xA09A28AC : {
        KEEP(*(.text.CallRecords_Delete_DisableMessage_CannotBeDeleted))
    }
    .CallRecords_Delete_FixClose 0xA09A27D4 : {
        KEEP(*(.text.CallRecords_Delete_FixClose))
    }

    .CallsList_OnCreate_Hook 0xA1382D60 : {
        KEEP(*(.text.CallsList_OnCreate_Hook))
    }
    .CallsList_OnCreate_Jump 0xA0C60BF4 : {
        KEEP(*(.data.CallsList_OnCreate_Jump))
    }
    .CallsList_OnClose_Hook 0xA1382DC0 : {
        KEEP(*(.text.CallsList_OnClose_Hook))
    }
    .CallsList_OnClose_Jump 0xA0C60C08 : {
        KEEP(*(.data.CallsList_OnClose_Jump))
    }
    .CallsList_GHook_Hook 0xA1382ED0 : {
        KEEP(*(.text.CallsList_GHook_Hook))
    }
    .CallsList_GHook_Jump 0xA0C7D028 : {
        KEEP(*(.data.CallsList_GHook_Jump))
    }
    .CallsList_DisablePleaseWait 0xA0A82D2E : {
        KEEP(*(.text.CallsList_DisablePleaseWait))
    }

    .CallsList_View_OnClose_Hook 0xA1382E10 : {
        KEEP(*(.text.CallsList_View_OnClose_Hook))
    }
    .CallsList_View_OnClose_Jump 0xA0C2C290 : {
        KEEP(*(.data.CallsList_View_OnClose_Jump))
    }
    .CallsList_View_GHook_Hook 0xA1382F40 : {
        KEEP(*(.text.CallsList_View_GHook_Hook))
    }
    .CallsList_View_GHook_Jump 0xA0C42EB0 : {
        KEEP(*(.data.CallsList_View_GHook_Jump))
    }
    .CallsList_View_FixClose 0xA08F6424 : {
        KEEP(*(.text.CallsList_View_FixClose))
    }

    .CallsList_Options_OnCreate_Hook 0xA1382E50 : {
        KEEP(*(.text.CallsList_Options_OnCreate_Hook))
    }
    .CallsList_Options_OnCreate_Jump 0xA0C42D60 : {
        KEEP(*(.data.CallsList_Options_OnCreate_Jump))
    }
    .CallsList_Options_OnClose_Hook 0xA1382E80 : {
        KEEP(*(.text.CallsList_Options_OnClose_Hook))
    }
    .CallsList_Options_OnClose_Jump 0xA0C42D74 : {
        KEEP(*(.data.CallsList_Options_OnClose_Jump))
    }
    .CallsList_Options_SendMsg_FixClose 0xA09A2C7E : {
        KEEP(*(.text.CallsList_Options_SendMsg_FixClose))
    }
    .CallsList_Options_FixIndents_Part1 0xA0C60C54 : {
        KEEP(*(.data.CallsList_Options_FixIndents_Part1))
    }
    .CallsList_Options_FixIndents_Part2 0xA0C60CB0 : {
        KEEP(*(.data.CallsList_Options_FixIndents_Part2))
    }
    .CallsList_Options_FixIndents_Part3 0xA0C60CCC : {
        KEEP(*(.data.CallsList_Options_FixIndents_Part3))
    }
}
