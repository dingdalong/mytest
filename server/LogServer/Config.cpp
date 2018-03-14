#include "GlobalDefine.h"
#include "config.h"
#include "tinyxml2.h"
#include "log.h"
#include "fmt/ostream.h"

using namespace tinyxml2;

CConfig::CConfig()
{
	s_DBName.clear();
	s_DBUser.clear();
	s_DBPass.clear();
	s_DBIP.clear();
	m_SQLLog = false;
}
CConfig::~CConfig()
{
	s_DBName.clear();
	s_DBUser.clear();
	s_DBPass.clear();
	s_DBIP.clear();
	m_SQLLog = false;
}

bool CConfig::Init(const char *servername)
{
	if (!CBaseConfig::Init(servername))
		return false;

	SetServerType(ServerEnum::EST_LOG);

	std::string filename = fmt::format("./config/{0}Config.xml", servername);
	XMLDocument doc;
	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
	{
		log_error("加载 %s 失败!", filename.c_str());
		return false;
	}

	XMLElement *pinfo = doc.FirstChildElement(servername);
	if (!pinfo)
	{
		log_error("没有找到节点：'%s'", servername);
		return false;
	}

	s_DBName = pinfo->Attribute("DBName");
	if (s_DBName.empty())
	{
		log_error("没有找到字段： 'DBName'");
		return false;
	}

	s_DBUser = pinfo->Attribute("DBUser");
	if (s_DBUser.empty())
	{
		log_error("没有找到字段： 'DBUser'");
		return false;
	}

	s_DBPass = pinfo->Attribute("DBPass");
	if (s_DBPass.empty())
	{
		log_error("没有找到字段： 'DBPass'");
		return false;
	}

	s_DBIP = pinfo->Attribute("DBIP");
	if (s_DBIP.empty())
	{
		log_error("没有找到字段： 'DBIP'");
		return false;
	}

	if (pinfo->QueryBoolAttribute("SQL_Log", &m_SQLLog) != XML_SUCCESS)
	{
		log_error("没有找到字段： 'SQL_Log'");
		return false;
	}

	return true;
}