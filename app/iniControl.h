#ifndef _INI_CONTROL_H_
#define _INI_CONTROL_H_

class CIniFile
{
	bool     load_ini_buf(char* buf,int *len);
	bool     parse_ini_buf(const char* buf,const char* section,const char* key,
		int *s_0,int *s_1,int *k_0,int *k_1,int *v_0,int *v_1);
	bool     ReadStr(const char* section,const char* key,char *value,int len,const char* def_value="");

public:
	CIniFile(const char* filename = 0);
	~CIniFile();
	void     ClearContents();
	void     Load(const char* filename);
	char*    ReadString(const char* section,const char* key,const char* def_value="");
	int      ReadInt(const char* section,const char* key,const int def_value);
	double   ReadFloat(const char* section,const char* key,const double def_value);
    bool     ReadBool(const char* section,const char* key,const bool def_value);
	bool     WriteString(const char* section,const char* key,const char* value);
	bool     WriteInt(const char* section,const char* key,const int value);
	bool     WriteFloat(const char* section,const char* key,const double value);
    bool     WriteBool(const char* section,const char* key,const bool value);
	void     EraseSection(const char* section);
private:
	char     m_filename[256]; 
};

#endif
