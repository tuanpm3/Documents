// log4cpp.cpp
// note : neu khong set hay add appender cho Category thi mac dinh la log se printf ra console
#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"

int main(int argc, char** argv) {
 log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console", &std::cout);
 appender1->setLayout(new log4cpp::BasicLayout());

 log4cpp::Appender *appender2 = new log4cpp::FileAppender("default", "program.log");
 appender2->setLayout(new log4cpp::BasicLayout());

 log4cpp::Category& root = log4cpp::Category::getRoot();
//root.setPriority(log4cpp::Priority::INFO);
 root.addAppender(appender2);

 log4cpp::Category& syslog = log4cpp::Category::getInstance(std::string("LOG_RECORD"));
 syslog.addAppender(appender1);

 // use of functions for logging messages
 syslog.info("error");
 syslog.info("warn");

 // printf-style for logging variables
 //root.warn("%d + %d == %s ?", 1, 1, "two");

 // use of streams for logging messages
 //syslog << log4cpp::Priority::ERROR << "Streamed root error";
 //syslog << log4cpp::Priority::INFO << "Streamed root info";
 //syslog << log4cpp::Priority::ERROR << "Streamed sub1 error";
 //syslog << log4cpp::Priority::WARN << "Streamed sub1 warn";

 // or this way:
 //syslog.errorStream() << "Another streamed error";

 return 0;
}