//DRAW_HOOK_v1.9 (C)Dimadze 2010 (Only SGold, Hee, hee, hee :D)

//1.0 - ������ ��������� ������
//1.1 - ��������� �����������
//1.2 - ��������� ��������� ��������������� 
//1.3 - ��������� ��������� ��������� 32-������ ����������� � ��������� ����
//1.4 - ���� ��������� � ������ �����
//1.5 - ��������� ��������� ��������� 32-������ ����������� � ��������� ���� Java, ���� ������ ��� ���������
//1.6 - ��������� ��������� ��������� 32-������ ����������� � Java, ��������� ��� ������ 1.5
//1.7 - ��������� ��������� ��������� 32� ���������� ����������� ������� 0x8A
//1.8 - ��������� � ��������� ��������� ��������� 32� ���������� ����������� ������� 0x8A
//1.9 - ��������� ��������� � ���� ��������� �������������� ����������� � ����� ��� X75

//���� �� ����������� (��� ����� "Linking") ��� �� ����������� postbuild.cmd �������� Project -> Clean
//���� � ������� �� ������ ��������� ���������, ����� �� ����� ����������� elf->vkp


#ifdef SL65sw53
#endif



#ifdef S65sw58
#endif



#ifdef CX70sw56
#endif



#ifdef SK65sw50
#endif



#ifdef CX75sw25
#define X75
//���������� ��� Draw Hook
#define EXC_CSM_MP 0xA04B8A60 //CSM �����������
#define EXC_CSM_ZP 0xA04D9C7C //CSM Zoom
#endif

#ifdef C75sw22
#define X75
//���������� ��� Draw Hook
#define EXC_CSM_MP 0xA04A9510 //CSM �����������
#define EXC_CSM_ZP 0xA04B2DF0 //CSM Zoom
#endif
