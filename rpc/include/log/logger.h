#pragma once

namespace WW
{

/**
 * @brief 日志
*/
class logger
{
private:
    logger();

    logger(const logger & other) = delete;

    logger & operator=(const logger & other) = delete;

public:
    ~logger();

public:
    /**
     * @brief 获取日志实例
    */
    static logger & get_logger();
};

} // namespace WW
