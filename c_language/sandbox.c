unsigned int sub_80484EB()
{
  char buf; // [esp+Ch] [ebp-2Ch]
  unsigned int v2; // [esp+2Ch] [ebp-Ch]

  v2 = __readgsdword(0x14u);
  printf("hello\n> ");                          // __readgsdword  �̰� ����
  read(0, &buf, 0x24u);
  printf("your data : %s", &buf);               // // ī���� 
  read(0, &buf, 0x80u);
  return __readgsdword(0x14u) ^ v2;
}