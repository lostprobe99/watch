#ifndef PROBE_WATCH_H
#define PROBE_WATCH_H

#include <chrono>

namespace probe
{
    class watch
    {
    public:
        typedef decltype(std::chrono::high_resolution_clock::now()) diff_point;

    private:
        diff_point m_start, m_end;

    public:
        watch(/* args */);
        ~watch();
        // nano second of timer
        double get_ns() const;
        // micro second of timer
        double get_mis() const;
        // milli second of timer
        double get_ms() const;
        // second of timer
        double get_s() const;
        // minuths of timer
        double get_min() const;
        // hours of timer
        double get_h() const;

        // start timer
        void start();
        // end timer
        void end();

        // get time now
        char * now(char * str, std::size_t count, const char * fmt = "%Y/%m/%d %a %H:%M:%S") const;
        // get date now includes years, months, days
        char * get_date(char * str, std::size_t count, const char * ysep = "/", const char * msep = "/", const char * dsep = "") const;
        // get time now includes hours, minuths, seconds
        char * get_time(char * str, std::size_t count) const;
        // get weekdays now from SUN to SAT
        int16_t get_weekday() const;

        // get years now
        uint32_t get_year() const;
        // get months now
        uint32_t get_month() const;
        // get days now
        uint32_t get_day() const;
        // get hours now
        uint32_t get_hours() const;
        // get minuths now
        uint32_t get_minuths() const;
        // get seconds now
        uint32_t get_seconds() const;
    };
} // namespace probe
#endif
