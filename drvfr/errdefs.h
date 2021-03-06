#pragma once
#ifndef ERRDEFS_H
#define ERRDEFS_H

namespace DriverFR
{

const char *errmsg[] =
{
	"������ ���",                                                //0   0
	"���������� ���������� �� 1, �� 2 ��� ����",                 //1   1
	"����������� �� 1",                                          //2   2
	"����������� �� 2",                                          //3   3
	"������������ ��������� � ������� ��������� � ��",           //4   4
	"��� ����������� ������",                                    //5   5
	"�� � ������ ������ ������",                                 //6   6
	"������������ ��������� � ������� ��� ������ ���������� ��", //7   7
	"������� �� �������������� � ������ ���������� ��",          //8   8
	"������������ ����� �������",                                //9   9
	"������ ������ �� BCD",                                      //0A 10
	"���������� ������ ������ �� ��� ������ �����",              //0B 11
	"",                                                          //0C 12
	"",                                                          //0D 13
	"",                                                          //0E 14
	"",                                                          //0F 15
	"",                                                          //10 16
	"�� ������� ��������",                                       //11 17
	"��������� ����� ��� ������",                                //12 18
	"������� ���� ������ ���� ��������� ������ � ��",            //13 19
	"������� ������� ������ �� �����������",                     //14 20
	"����� ��� �������",                                         //15 21
	"����� �� �������",                                          //16 22
	"����� ������ ����� ������ ������ ��������� �����",          //17 23
	"���� ������ ����� ������ ���� ��������� �����",             //18 24
	"��� ������ � ��",                                           //19 25
	"������� ��������������� � �� �����������",                  //1A 26
	"��������� ����� �� ������",                                 //1B 27
	"� �������� ��������� ���� ������������ ������",             //1C 28
	"���������� ��������� ������ ������� ������",                //1D 29
	"������� ��������������� �� �����������",                    //1E 30
	"����������� ������ ���������",                              //1F 31
	"������������ ��������� �������� ��� ����������",            //20 32
	"���������� ����� ������ ����������� ��������� ��������",    //21 33
	"�������� ����",                                             //22 34
	"��� ������ �����������",                                    //23 35
	"������� ����������� �����������",                           //24 36
	"��� ����������� � ������������� �������",                   //25 37
	"�������� �������� ����� ������ ����� ����",                 //26 38
	"",                                                          //27 39
	"",                                                          //28 40
	"",                                                          //29 41
	"",                                                          //2A 42
	"���������� �������� ���������� �������",                    //2B 43
	"��������� ����� (��������� ������� ����������)",           //2C 44
	"����� ���� �� ������ ������ ����� ������",                  //2D 45
	"� �� ��� ����� ��� �������",                                //2E 46
	"",                                                          //2F 47
	"�� ������������, ���� ����� ������ ���������� ����������",  //30 48
	"",                                                          //31 49
	"��������� ���������� ������ �������",                       //32 50
	"������������ ��������� � �������",                          //33 51
	"��� ������",                                                //34 52
	"������������ �������� ��� ������ ����������",               //35 53
	"������������ ��������� � ������� ��� ������ ���������� ��", //36 54
	"������� �� �������������� � ������ ���������� ��",          //37 55
	"������ � ���",                                              //38 56
	"���������� ������ �� ��",                                   //39 57
	"������������ ���������� �� ��������� � �����",              //3A 58
	"������������ ���������� � �����",                           //3B 59
	"����� ������� � �������� ����������",                       //3C 60
	"����� �� ������� � �������� ����������",                    //3D 61
	"������������ ���������� �� ������� � �����",                //3E 62
	"������������ ���������� �� ������� � �����",                //3F 63
	"������������ ��������� ������",                             //40 64
	"������������ ��������� ������ ���������",                   //41 65
	"������������ ��������� ������ ����� 2",                     //42 66
	"������������ ��������� ������ ����� 3",                     //43 67
	"������������ ��������� ������ ����� 4",                     //44 68
	"C���� ���� ����� ������ ������ ����� ����",                 //45 69
	"�� ������� ���������� � �����",                             //46 70
	"������������ ���������� �� ������� � �����",                //47 71
	"������������ ����� ����",                                   //48 72
	"�������� ���������� � �������� ���� ������� ����",          //49 73
	"������ ��� � �������� ����������",                          //4A 74
	"����� ���� ����������",                                     //4B 75
	"������������ ���������� �� ������� ������� � �����",        //4C 76
	"�������� ����������� ������� ����� ������ ����� ����",      //4D 77
	"����� ��������� 24 ����",                                   //4E 78
	"�������� ������",                                           //4F 79
	"���� ������ ���������� �������",                            //50 80
	"������������ ���������� ��������� � �����",                 //51 81
	"������������ ���������� �� ���� ������ 2 � �����",          //52 82
	"������������ ���������� �� ���� ������ 3 � �����",          //53 83
	"������������ ���������� �� ���� ������ 4 � �����",          //54 84
	"��� ������ � �������� ����������",                          //55 85
	"��� ��������� ��� �������",                                 //56 86
	"����: ���������� �������� ���� �� ��������� � ��",          //57 87
	"�������� ������� ����������� ������",                       //58 88
	"�������� ������ ������ ����������",                         //59 89
	"������ ��������� ���������� � ����",                        //5A 90
	"������������ ��������� ��������",                           //5B 91
	"�������� ���������� 24�",                                   //5C 92
	"������� �� ����������",                                     //5D 93
	"������������ ��������",                                     //5E 94
	"������������� ���� ����",                                   //5F 95
	"������������ ��� ���������",                                //60 96
	"������������ ��������� ����",                               //61 97
	"������������ ��������� ����������",                         //62 98
	"������������ ��������� ������",                             //63 99
	"�� �����������",                                            //64 100
	"�� ������� ����� � ������",                                 //65 101
	"������������ ����� � ������",                               //66 102
	"������ ����� � ��",                                         //67 103
	"�� ������� ����� �� ������� �������",                       //68 104
	"������������ ����� �� ������� �������",                     //69 105
	"������ ������� � ������ ������ �� I2C",                     //6A 106
	"��� ������� �����",                                         //6B 107
	"��� ����������� �����",                                     //6C 108
	"�� ������� ����� �� ������",                                //6D 109
	"������������ ����� �� ������",                              //6E 110
	"������������ �� ������� � �����",                           //6F 111
	"������������ ��",                                           //70 112
	"������ ���������",                                          //71 113
	"������� �� �������������� � ������ ���������",              //72 114
	"������� �� �������������� � ������ ������",                 //73 115
	"������ ���",                                                //74 116
	"������ �������",                                            //75 117
	"������ ��������: ��� ��������� � ��������������",           //76 118
	"������ ��������: ��� ������� � ��������",                   //77 119
	"������ ��",                                                 //78 120
	"������ ��",                                                 //79 121
	"���� �� �������������",                                     //7A 122
	"������ ������������",                                       //7B 123
	"�� ��������� ����",                                         //7C 124
	"�������� ������ ����",                                      //7D 125
	"�������� �������� � ���� �����",                            //7E 126
	"������������ ��������� ����� ����",                         //7F 127
	"������ ����� � ��",                                         //80 128
	"������ ����� � ��",                                         //81 129
	"������ ����� � ��",                                         //82 130
	"������ ����� � ��",                                         //83 131
	"������������ ����������",                                   //84 132
	"������������ �� �������� � �����",                          //85 133
	"������������ �� �������� � �����",                          //86 134
	"������������ �� ��������� ������ � �����",                  //87 135
	"������������ �� ��������� ������� � �����",                 //88 136
	"������������ �� �������� � �����",                          //89 137
	"������������ �� ��������� � ����",                          //8A 138
	"������������ �� ������� � ����",                            //8B 139
	"������������� ���� �������� � ����",                        //8C 140
	"������������� ���� ������ � ����",                          //8D 141
	"������� ���� ����",                                         //8E 142
	"����� �� ���������������",                                  //8F 143
	"���� ��������� ������, ������������� � ����������",         //90 144
	"����� �� ������� ���� ������ ��� ������ ���������� ������", //91 145
	"��������� �����",                                           //92 146
	"�������������� ��� ������ �������",                         //93 147
	"�������� ����� �������� � ����",                            //94 148
	"",                                                          //95 149
	"",                                                          //96 150
	"",                                                          //97 151
	"",                                                          //98 152
	"",                                                          //99 153
	"",                                                          //9A 154
	"",                                                          //9B 155
	"",                                                          //9C 156
	"",                                                          //9D 157
	"",                                                          //9E 158
	"",                                                          //9F 159
	"������ ����� � ����",                                       //A0 160
	"���� �����������",                                          //A1 161
	"����: ������������ ������ ��� �������� �������",            //A2 162
	"������������ ��������� ����",                               //A3 163
	"������ ����",                                               //A4 164
	"������ �� � ������� ����",                                  //A5 165
	"�������� ��������� ������ ����",                            //A6 166
	"���� �����������",                                          //A7 167
	"����: �������� ���� � �����",                               //A8 168
	"����: ��� ����������� ������",                              //A9 169
	"������������ ���� (������������� ���� ���������)",          //AA 170
	"",                                                          //AB 171
	"",                                                          //AC 172
	"",                                                          //AD 173
	"",                                                          //AE 174
	"",                                                          //AF 175
	"����: ������������ � ��������� ����������",                 //B0 176
	"����: ������������ � ��������� �����",                      //B1 177
	"����: ��� ��������������",                                  //B2 178
	"",                                                          //B3 179
	"",                                                          //B4 180
	"",                                                          //B5 181
	"",                                                          //B6 182
	"",                                                          //B7 183
	"",                                                          //B8 184
	"",                                                          //B9 185
	"",                                                          //BA 186
	"",                                                          //BB 187
	"",                                                          //BC 188
	"",                                                          //BD 189
	"",                                                          //BE 190
	"",                                                          //BF 191
	"�������� ���� � ������� (����������� ���� � �����)",        //C0 192
	"����: �������� ����� � �������� �������� ������",           //C1 193
	"���������� ���������� � ����� �������",                     //C2 194
	"������������ ������ ���� � ����",                           //C3 195
	"������������ ������� ����",                                 //C4 196
	"����� ����������� ��������� ����",                          //�5 197
	"���������� �������� �����������",                           //C6 198
	"���� �� ������������� � ������ ������"                      //C7 199
};

const char *ecrmodedesc[] =
{
	"",                                                         //0
	"������ ������",                                            //1
	"�������� �����, 24 ���� �� ���������",                     //2
	"�������� �����, 24 ���� ���������",                        //3
	"�������� �����",                                           //4
	"���������� �� ������������� ������ ���������� ����������", //5
	"�������� ������������� ����� ����",                        //6
	"���������� ��������� ��������� ���������� �����",          //7
	"�������� ��������",                                        //8
	"����� ���������� ���������������� ���������",              //9
	"�������� ������",                                          //10
	"������ ������� ���. ������",                               //11
	"������ ������ ����",                                       //12
	"������ � ���������� ���������� ����������",                //13
	"������ ����������� ���������",                             //14
	"���������� ���������� �������� �����������"                //15
};

const char *ecrmode8desc[] =
{
	"��� ������� ������",
	"��� ������� ������",
	"��� �������� ������� ������",
	"��� �������� ������� ������"
};

const char *ecrsubmodedesc[] =
{
	"������ ����",
	"��������� ���������� ������",
	"�������� ���������� ������",
	"�� ���� ������� ����������� ������",
	"���� ������ �������� ������ ���������� �������",
	"���� ������ ��������"
};

const char *devcodedesc[] =
{
	"FM1 flash",
	"FM2 flash",
	"Clock",
	"Powerindependent memory",
	"FM processor",
	"FR usr memory",
	"FR base memory"
};

}
#endif
