#ifndef CUSTOMEXCEPTION_HPP
#define CUSTOMEXCEPTION_HPP

#include <exception>
#include <string>
#include <sstream>
#include <iostream>

// 异常时,将文件名、行号、函数名和详细信息+上一层的异常一起抛出
#define THROW_EXCEPTION(exMsg)\
{\
     std::ostringstream message;\
     message <<"File: "<<__FILE__<<"\n"\
             <<"Line:"<<__LINE__<<"\n"\
             <<"Func:"<<__FUNCTION__<<"\n"\
             <<"Detail:"<< exMsg <<"\n";\
     std::string msg = message.str();\
     throw  SDK::CustomException(msg);\
}

namespace SDK
{
/**
 *  @brief CustomException
 *
 *  @author peter
 *  @version 1.00 2017-11-21 peter
 *                note:create it
 */
    class CustomException : public std::exception
    {

    public:
//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // constructor & destructor
        /**
         * @brief CustomException
         *      构造函数
         * @param N/A
         * @return N/A
         */
        CustomException();
        /**
         * @brief CustomException
         *      构造函数
         * @param message
         *      需要显示的异常信息
         * @return N/A
         */
        CustomException(std::string& message);
        /**
         * @brief ~CustomException
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual ~CustomException();

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        const std::string originalMsg ( )const{return this->m_originalMsg;}
        virtual const char* what() const _GLIBCXX_USE_NOEXCEPT override{return m_originalMsg.data();}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_originalMsg;
    };

}

#endif // CUSTOMEXCEPTION_HPP
