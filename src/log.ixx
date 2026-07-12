///////////////////////////////////////////////////////////////////////////
/// @file   log.ixx
/// @author Sultan Luchezarniy (Xottab_DUTY)
/// @brief  Logging
///////////////////////////////////////////////////////////////////////////

module;

#include "fixed_string.hpp"

export module xeyday.log;

export namespace xeyday::logging
{
enum class log_level
{
    disabled,

    trace,
    debug,

    warning,
    info,
    error,

    critical
};

class logger
{
    const char*                 m_name;

public:
    explicit        logger      ( const char* name ) : m_name( name ) { }

    template                    < typename... Args >
    void            log         ( const log_level level, const char* format_string, Args&&... args )
    {
        if ( level == log_level::disabled )
            return;

        (void)level;
        (void)format_string;
        (void)args;
    }
};

template < fixstr::fixed_string LoggerName >
class namespace_logger
{
    inline static logger        m_logger{ LoggerName.c_str() };

public:
    namespace_logger            ( ) = delete;
    namespace_logger            ( namespace_logger&  ) = delete;
    namespace_logger            ( namespace_logger&& ) = delete;
    namespace_logger& operator= ( namespace_logger&  ) = delete;
    namespace_logger& operator= ( namespace_logger&& ) = delete;

public:
    template                    < typename... Args >
    static void     log         ( const log_level level, const char* format_string, Args&&... args )
    {
        m_logger.log            ( level, format_string, std::forward<Args>(args)... );
    }

    template                    < typename... Args >
    static void     trace       ( const char* format_string, Args&&... args )
    {
        m_logger.log            ( log_level::trace, format_string, std::forward<Args>(args)... );
    }

    template                    < typename... Args >
    static void     debug       ( const char* format_string, Args&&... args )
    {
        m_logger.log            ( log_level::debug,    format_string, std::forward<Args>(args)... );
    }

    template                    < typename... Args >
    static void     warning     ( const char* format_string, Args&&... args )
    {
        m_logger.log            ( log_level::warning,  format_string, std::forward<Args>(args)... );
    }

    template                    < typename... Args >
    static void     info        ( const char* format_string, Args&&... args )
    {
        m_logger.log            ( log_level::info,     format_string, std::forward<Args>(args)... );
    }

    template                    < typename... Args >
    static void     error       ( const char* format_string, Args&&... args )
    {
        m_logger.log            ( log_level::error,    format_string, std::forward<Args>(args)... );
    }

    template                    < typename... Args >
    static void     critical    ( const char* format_string, Args&&... args )
    {
        m_logger.log            ( log_level::critical, format_string, std::forward<Args>(args)... );
    }
};
} // export namespace xeyday::logging
