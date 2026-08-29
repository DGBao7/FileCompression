#include "AnalyzePath.h"
#include <vector>
#include <string>

std::vector<std::string> Choppath(const std::string& path)
{
    std::vector<std::string> path_part;

    std::string part = "";

    for (size_t i = 0; i < path.size(); i ++)
    {
        if (path[i] == '\\' || path[i] == '/')
        {
            path_part.push_back(part);
            part = "";
            continue;
        }

        part += path[i];
    }

    if (part.size() != 0)
    {
        path_part.push_back(part);
    }

    return  path_part;
}

std::string RewritePath(std::vector<std::string> part_path)
{
    std::string loc_path;

    for (size_t i = 0; i < part_path.size(); i ++)
    {
        loc_path += part_path[i] + "\\";
    }

    return loc_path;
}

std::vector<std::string> ChopName(std::string file)
{
    std::vector<std::string> name;
    std::string file_name = "";
    std::string extension = "";
    bool flag = true;

    for (size_t i = 0; i < file.size(); i ++)
    {
        if (file[i] == '.')
        {
            flag = false;
        }

        if (flag)
        {
            file_name += file[i];
        }
        else
        {
            extension += file[i];
        }
    }

    name.push_back(file_name);
    name.push_back(extension);

    return name;
}