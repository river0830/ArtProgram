#include "iniControl.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
/*#define	(LPCTSTR)	(const char*)	*/	
typedef const char * LPCTSTR;

static const int Q_INI_SIZE = 0x2000;
CIniFile::CIniFile(const char* filename)
{
	memset(m_filename,0,256);
	if (filename != 0)
	{
		int len = strlen(filename);
		memcpy(m_filename,(char *)filename,len);
		m_filename[len] = '\0';
	}
}
CIniFile::~CIniFile(){
}
void CIniFile::Load(const char* filename)
{
	int len = strlen(filename);
	memset(m_filename,0,256);
	memcpy(m_filename,(LPCTSTR)filename,len);
	m_filename[len] = (char)'\0';
}
void CIniFile::ClearContents()
{
	FILE *f = fopen(m_filename,"w+");
	if (f != NULL)
	{
		fclose(f);
	}
}
bool CIniFile::load_ini_buf(char* buf,int *len) 
{
	int i = 0;
	bool ret = false;
	*len = 0;

	FILE *f = fopen(m_filename,"r");
	if (f != NULL)
	{
		if (buf !=NULL)
		{
			buf[i] = fgetc(f);
			while(buf[i] != (char)EOF){
				i++;
				buf[i] = fgetc(f);;
			}
			buf[i] = '\0';
			*len = i;
			ret = true;
		}
		fclose(f);
	}
	return ret;
}
bool  CIniFile::parse_ini_buf(const char* buf,const char* section,const char* key,
	int *s_0,int *s_1,int *k_0,int *k_1,int *v_0,int *v_1)
{
	unsigned int i = 0;
	unsigned int len = strlen(key);
	bool ret = false;
	const char* p = buf;

	*s_0 = *s_1 = *k_0 = *k_1 = *v_0 = *v_1 = -1;
	while (p[i] != '\0')
	{
		if ( p[i] =='[' && (i==0 || (p[i-1] == '\r' || p[i-1] == '\n')) ) //Find '['
		{
			//Section Symbol Begin
			int s_i = i+1;
			do{
				i++;
			}while( p[i] !=']' && p[i] != '\0');
			if (strncmp(p+s_i,section,i-s_i)==0 && strlen(section) ==(i-s_i) )
			{
				unsigned int t = 0;
				i++;
				while(isspace(p[i])) {i++;}
				*s_0 = s_i;
				*s_1 = i;
				//Section Symbol End      
				while ((p[i] != '\0') &&  !(p[i] =='[' && (p[i-1] == '\r' || p[i-1] == '\n')) ){//not End and New Section
					unsigned int m = 0;
					t = i;//new line begin
					while( !(p[i] == '\r' || p[i] == '\n') && (p[i] != '\0')){ i++;}//new line end
					m = t;

					if (p[m] != ';' || ( (m < i - 1) && p[m] != '/' && p[m+1] !='/' ))//skip comment
					{
						while (m < i && p[m] != '=')// format: key = value 
						{
							m++;
							if (p[m] == '=')
							{
								//я╟ур©у╦Я
								unsigned int spaceCnt = 0;
								for(int a=m-1; a>t; a--)
								{
									if((p[a] == ' ') || (p[a] == '\t'))
									{
										spaceCnt++;
									}
									else
									{
										break;
									}
								}
								if ((m-t-spaceCnt)<len)
									m = t + len;
								if (strncmp(key,p+t,m-t-spaceCnt)==0)
								{
									*k_0 = t;
									*k_1 = m-1-spaceCnt;
									*v_0 = m+1;
									*v_1 = i;
									ret = true;
									goto F_EXIT;
								}
							}
						}
					}
					i++;
					//Key No Find ,Let Go To Section End
					if (p[i] == '[' || p[i] == '\0'){      
						*s_1 = i;
						ret = true;
						goto F_EXIT;
					}
				}
			}
		}else i++;
	}
F_EXIT:
	return ret;
}
bool  CIniFile::ReadStr(const char* section,const char* key,char *value,int len,const char* def_value){
	int s_0,s_1,k_0,k_1,v_0,v_1;
	char buf[Q_INI_SIZE]; 
	int  blen;
	bool ret = false;
	if (section!= NULL && key != NULL && value !=NULL)
	{
		if (!load_ini_buf(buf,&blen))
			goto F_NOT_FIND;
		if (!parse_ini_buf(buf,section,key,&s_0,&s_1,&k_0,&k_1,&v_0,&v_1))
			goto F_NOT_FIND;
		else{
			blen = v_1 - v_0;
			if (blen > len - 1)
				blen = len - 1;
			memset(value,0,len);
			memcpy(value,buf+v_0,blen);
			value[blen] = '\0';
			ret = true;
			goto F_EXIT;
		}
	}
F_NOT_FIND:
	if (def_value != NULL)
		strncpy(value,def_value,len);
F_EXIT:
	return ret;
}
char*  CIniFile::ReadString(const char* section,const char* key,const char* def_value)
{
	static char  geo_kd_buf[1025] = {0};
	memset(geo_kd_buf, 0, sizeof(geo_kd_buf));

	ReadStr(section,key,geo_kd_buf,1024,def_value);
	return geo_kd_buf;
}
int   CIniFile::ReadInt(const char* section,const char* key,const int def_value){
	char v[32]={0};
	if (!ReadStr(section,key,v,sizeof(v),NULL))
		return def_value;
	else return atoi(v);
}
double CIniFile::ReadFloat(const char* section, const char* key,const double def_value){
	char v[32]={0};
	if (!ReadStr(section,key,v,sizeof(v),NULL))
		return def_value;
	else return atof(v);
}
bool CIniFile::ReadBool(const char* section,const char* key,const bool def_value){
	char v[32]={0};
	if (!ReadStr(section,key,v,sizeof(v),NULL))
		return def_value;
	else {
		if (strncmp(v,"true",4)==0)
			return true;
		else if (strncmp(v,"false",5)==0)
			return false;
		else return def_value;
	};
}
bool  CIniFile::WriteString(const char* section,const char* key,const char* value){
	int s_0,s_1,k_0,k_1,v_0,v_1,blen;
	char buf[Q_INI_SIZE]={0}; 
	char m_buf[Q_INI_SIZE]={0}; 
	int  vlen = strlen(value);
	bool ret = false;
	if (section!= NULL && key != NULL && value !=NULL)
	{
		if (!load_ini_buf(buf,&blen))
			s_0 = -1;
		else parse_ini_buf(buf,section,key,&s_0,&s_1,&k_0,&k_1,&v_0,&v_1);
		if (s_0 == -1)//Section not exist
		{
			if (blen == 0)
			{
				sprintf(m_buf+blen,"[%s]\n%s=%s\n",section,key,value);
			}else{
				while(blen>0 && buf[blen-1]=='\n')
					blen--;
				memcpy(m_buf,buf,blen);
				sprintf(m_buf+blen,"\n[%s]\n%s=%s\n",section,key,value);
			}
		}else if (k_0 == -1) //Section exist and Key not exist
		{
			memcpy(m_buf,buf,s_1);
			sprintf(m_buf+s_1,"%s=%s\n",key,value);
			sprintf(m_buf+s_1+strlen(key)+strlen(value)+2,buf+s_1,blen-v_1);
		}else{//Section exist and Key exist ,update this value
			memcpy(m_buf,buf,v_0);
			memcpy(m_buf+v_0,value,vlen);
			memcpy(m_buf+v_0+vlen,buf+v_1,blen-v_1);  
		}
		FILE *f = fopen(m_filename,"w");
		if (f != NULL)
		{
			if (fputs(m_buf,f)==-1)
			{
				fclose(f);
				goto F_EXIT;
			}
			fclose(f);
		}
		ret = true;
	}
F_EXIT:
	return ret;
}
bool  CIniFile::WriteInt(const char* section,const char* key,const int value){
	char v[32]={0}; 
	sprintf(v,"%d",value);
	return WriteString(section,key,v);
}
bool  CIniFile::WriteFloat(const char* section,const char* key,const double value){
	char v[32]={0};
	sprintf(v,"%f",value);
	return WriteString(section,key,v);
}
bool  CIniFile::WriteBool(const char* section,const char* key,const bool value){
	char v[32]={0};
	if (value==true)
	{
		memcpy(v,"true",4);
	}else memcpy(v,"false",5);
	return WriteString(section,key,v);
}
void  CIniFile::EraseSection(const char* section){
	int s_0,s_1,k_0,k_1,v_0,v_1,blen;
	char buf[Q_INI_SIZE]={0}; 
	char m_buf[Q_INI_SIZE]={0}; 
	if (section!= NULL)
	{
		if (!load_ini_buf(buf,&blen))
			goto F_EXIT;
		parse_ini_buf(buf,section,"",&s_0,&s_1,&k_0,&k_1,&v_0,&v_1);
		if (s_0 != -1)
		{
			memcpy(m_buf,buf,s_0-1);
			memcpy(m_buf+s_0-1,buf+s_1,blen-s_1);
			FILE *f = fopen(m_filename,"w");
			if (f != NULL)
			{
				if (fputs(m_buf,f)==-1)
				{
					fclose(f);
					goto F_EXIT;
				}
				fclose(f);
			}
		}
	}
F_EXIT:
	return;
}
