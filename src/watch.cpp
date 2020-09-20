#include "watch.h"

#include<chrono>
#include<cstdlib>
#include<cstdio>
#include<ctime>

namespace probe
{
    watch::watch(/* args */)
    {
    }

    watch::~watch()
    {
    }

    void watch::start()
    {
        m_start = std::chrono::high_resolution_clock::now();
    }

    void watch::end()
    {
        m_end = std::chrono::high_resolution_clock::now();
    }

    double watch::get_ns() const
    {
        std::chrono::duration<double, std::ratio<1, 1000000000>> diff = m_end - m_start;
        return diff.count();
    }

    double watch::get_mis() const
    {
        std::chrono::duration<double, std::ratio<1, 1000000>> diff = m_end - m_start;
        return diff.count();
    }

    // milli second
    double watch::get_ms() const
    {
        std::chrono::duration<double, std::ratio<1, 1000>> diff = m_end - m_start;
        return diff.count();
    }

    // second
    double watch::get_s() const
    {
        std::chrono::duration<double, std::ratio<1, 1>> diff = m_end - m_start;
        return diff.count();
    }

    double watch::get_min() const
    {
        std::chrono::duration<double, std::ratio<60, 1>> diff = m_end - m_start;
        return diff.count();
    }

    double watch::get_h() const
    {
        std::chrono::duration<double, std::ratio<3600, 1>> diff = m_end - m_start;
        return diff.count();
    }

    char * watch::now(char * str, std::size_t count, const char * fmt) const
    {
        std::time_t t = std::time(nullptr);
        if(std::strftime(str, count, fmt, std::localtime(&t))) {
            return str;
        }
        return 0;
    }

    char * watch::get_date(char * str, std::size_t count, const char * ysep, const char * msep, const char * dsep) const
    {
        const char * fmt = "%%Y%s%%m%s%%d%s";
        char buf[64]{0};
        sprintf(buf, fmt, ysep, msep, dsep);
        std::time_t t = std::time(nullptr);
        if(std::strftime(str, count, buf, std::localtime(&t))) {
            return str;
        }
        return nullptr;
    }

    char * watch::get_time(char * str, std::size_t count) const
    {
        const char *fmt = "%H:%M:%S";
        std::time_t t = std::time(nullptr);
        if(std::strftime(str, count, fmt, std::localtime(&t))) {
            return str;
        }
        return nullptr;
    }

    int16_t watch::get_weekday() const
    {
        std::time_t t = time(nullptr);
        int16_t wd = std::localtime(&t)->tm_wday;
        return wd;
    }

    uint32_t watch::get_year() const
    {
        char buf[16]{0};
        std::time_t t = std::time(nullptr);
        if(std::strftime(buf, sizeof(buf), "%Y", std::localtime(&t))) {
            return std::atoi(buf);
        }
        return 0;
    }

    uint32_t watch::get_month() const
    {
        char buf[16]{0};
        std::time_t t = std::time(nullptr);
        if(std::strftime(buf, sizeof(buf), "%m", std::localtime(&t))) {
            return std::atoi(buf);
        }
        return 0;
    }

    uint32_t watch::get_day() const
    {
        char buf[16]{0};
        std::time_t t = std::time(nullptr);
        if(std::strftime(buf, sizeof(buf), "%d", std::localtime(&t))) {
            return std::atoi(buf);
        }
        return 0;
    }

    uint32_t watch::get_hours() const
    {
        char buf[16]{0};
        std::time_t t = std::time(nullptr);
        if(std::strftime(buf, sizeof(buf), "%H", std::localtime(&t))) {
            return std::atoi(buf);
        }
        return 0;
    }

    uint32_t watch::get_minuths() const
    {
        char buf[16]{0};
        std::time_t t = std::time(nullptr);
        if(std::strftime(buf, sizeof(buf), "%M", std::localtime(&t))) {
            return std::atoi(buf);
        }
        return 0;
    }

    uint32_t watch::get_seconds() const
    {
        char buf[16]{0};
        std::time_t t = std::time(nullptr);
        if(std::strftime(buf, sizeof(buf), "%S", std::localtime(&t))) {
            return std::atoi(buf);
        }
        return 0;
    }

} // namespace probe
