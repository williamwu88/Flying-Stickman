#include "extendedconfigstage3.h"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <iostream>

ExtendedConfigStage3::ExtendedConfigStage3(Config& config)
    : ExtendedConfig(config){
    setupConfig();
}

void ExtendedConfigStage3::setupStage3Config(){
    QFile config_file(":config/config.txt");

    //Open the config file
    if(config_file.open(QIODevice::ReadOnly)){

        QTextStream buffer(&config_file);

        while(!buffer.atEnd()){

            QString line = buffer.readLine();

            QStringList split_line = line.split(":", QString::SkipEmptyParts);

            QString element = split_line.at(1);

            if(split_line.first() == "Size" ||
                    split_line.first() == "Position" ||
                    split_line.first() == "Velocity" ||
                    split_line.first() == "Background" ||
                    split_line.first() == "Obstacles"){
                continue;
            }else if(split_line.first() == "Level"){
                if (element.toInt() < 0 || element.toInt() == 0){
                    std::cerr << "Level is not valid. Level should be a number >0" << std::endl;
                    return;
                }

                level = element.toInt();
            }
        }

        config_file.close();
    }else{
        std::cerr << "Config file not found" << std::endl;
    }
}

