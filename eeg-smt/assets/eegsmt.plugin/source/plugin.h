#ifndef _EEGSMT_H_
#define _EEGSMT_H_

#include "coffee.h"
using namespace coffee;

//-IMPORT-EXPORT----------------------------------------------------------------------------------//
#ifndef USE_EEGSMT
    #define EEGSMT_API __declspec(dllexport)
    #define EEGSMT_TEMPLATE_API __declspec(dllexport)
#else
    #define EEGSMT_API __declspec(dllimport)
    #define EEGSMT_TEMPLATE_API
#endif

#ifdef USE_EEGSMT
    #define EEGSMT_EXPORT_STATICS false
#else
    #define EEGSMT_EXPORT_STATICS true
#endif
//------------------------------------------------------------------------------------------------//

namespace eegsmt
{
    //--------------------------------------------------------------------------------------------//
    /// eegsmt::Library
    //--------------------------------------------------------------------------------------------//
    class EEGSMT_API Library : public plugins::Library
    {
        COFFEE_Type(Library);

    public:

        //-CONSTRUCTORS---------------------------------------------------------------------------//

        Library();
        ~Library();

        //-OPERATIONS-----------------------------------------------------------------------------//

        void Initialize();
        void Finalize();
        void Update(const basic::Time& time_step);
        
    private:

        //-ATTRIBUTES-----------------------------------------------------------------------------//


    };

    COFFEE_RegisterType(EEGSMT_EXPORT_STATICS, Library);
}

COFFEE_RegisterPlugin(eegsmt::Library);

#endif
