#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Simpleini/SimpleIni.h"
#include <QString>

class Configuration
{
    CSimpleIniA iniFile;

    explicit Configuration(const std::string& fileName);

    static Configuration *instance;

public:

    static Configuration& GetInstance();

    static bool InitializeConfiguration(QString path);

    bool IsKeyAvailable(const std::string& section, const std::string& key) const;
    bool GetBoolValue(const std::string& section, const std::string& key) const;
    long GetLongValue(const std::string& section, const std::string& key) const;
    double GetDoubleValue(const std::string& section, const std::string& key) const;
    std::string GetStringValue(const std::string& section, const std::string& key) const;

    void SetBoolValue(const std::string& section, const std::string& key, bool value);
    void SetLongValue(const std::string& section, const std::string& key, long value);
    void SetDoubleValue(const std::string& section, const std::string& key, double value);
    void SetStringValue(const std::string& section, const std::string& key, const std::string& value);
};

#endif // CONFIGURATION_H
