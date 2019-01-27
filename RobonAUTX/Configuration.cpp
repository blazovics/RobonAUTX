#include "Configuration.h"

Configuration *Configuration::instance = nullptr;

bool Configuration::InitializeConfiguration(QString path)
{
    if(instance == nullptr)
    {
        instance = new Configuration(path.toStdString());
        return true;
    }
    return false;
}

Configuration::Configuration(const std::string& fileName)
{
    this->iniFile.SetUnicode();

    SI_Error e = this->iniFile.LoadFile(fileName.c_str());
    if(e < 0)
    {
        std::string errorMessage;
        switch(e){
        case SI_FAIL:
            errorMessage = "Generic failure";
            break;
        case SI_NOMEM:
            errorMessage = "Out of memory error";
            break;
        case SI_FILE:
            errorMessage = "File error (see errno for detail error)";
            break;
        case SI_OK:
        case SI_UPDATED:
        case SI_INSERTED:
            errorMessage = "Unexpected behaviour";
            break;
        }

        throw std::runtime_error(std::string("Configuration File was unable to parse with the following error: ") + errorMessage + std::string(" file name:") + fileName);
    }
}

Configuration &Configuration::GetInstance()
{
    return *instance;
}



bool Configuration::IsKeyAvailable(const std::string& section, const std::string& key) const
{
    const char* pszValue = this->iniFile.GetValue(section.c_str(), key.c_str());
    if (!pszValue || !*pszValue)
    {
        return false;
    }
    return true;
}

bool Configuration::GetBoolValue(const std::string& section, const std::string& key) const
{
    if(!this->IsKeyAvailable(section.c_str(),key.c_str()))
    {
        throw std::runtime_error(std::string("Project File - Unable to find bool value for key: ") + key + std::string(" in section:") + section);
    }
    else
    {
        return this->iniFile.GetBoolValue(section.c_str(),key.c_str());
    }
}

long Configuration::GetLongValue(const std::string& section, const std::string& key) const
{
    if(!this->IsKeyAvailable(section.c_str(),key.c_str()))
    {
        throw std::runtime_error(std::string("Project File - Unable to find int value for key: ") + key + std::string(" in section:") + section);
    }
    else
    {
        return this->iniFile.GetLongValue(section.c_str(),key.c_str());
    }
}

double Configuration::GetDoubleValue(const std::string& section, const std::string& key) const
{
    if(!this->IsKeyAvailable(section.c_str(),key.c_str()))
    {
        throw std::runtime_error(std::string("Project File - Unable to find float value for key: ") + key + std::string(" in section:") + section);
    }
    else
    {
        return this->iniFile.GetDoubleValue(section.c_str(),key.c_str());
    }
}

std::string Configuration::GetStringValue(const std::string& section, const std::string& key) const
{
    if(!this->IsKeyAvailable(section.c_str(),key.c_str()))
    {
        throw std::runtime_error(std::string("Project File - Unable to find string value for key: ") + key + std::string(" in section:") + section);
    }
    else
    {
        return std::string(this->iniFile.GetValue(section.c_str(),key.c_str()));
    }
}

void Configuration::SetBoolValue(const std::string& section, const std::string& key, bool value)
{
    this->iniFile.SetBoolValue(section.c_str(),key.c_str(),value);
}

void Configuration::SetLongValue(const std::string& section, const std::string& key, long value)
{
    this->iniFile.SetLongValue(section.c_str(),key.c_str(),value);
}

void Configuration::SetDoubleValue(const std::string& section, const std::string& key, double value)
{
    this->iniFile.SetDoubleValue(section.c_str(),key.c_str(),value);
}

void Configuration::SetStringValue(const std::string& section, const std::string& key, const std::string& value)
{
    this->iniFile.SetValue(section.c_str(),key.c_str(),value.c_str());
}
