#include "logger.h"

namespace WW
{

logger::logger()
{

}

logger::~logger()
{

}

logger & logger::get_logger()
{
    static logger log;
    return log;
}

} // namespace WW
