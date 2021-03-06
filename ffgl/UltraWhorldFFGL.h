#include <FFGLShader.h>
#include <FFGLPluginSDK.h>

#include <stdafx.h>
#include <MainFrm.h>


enum {
    NUM_INPUTS = 1,
    MAX_STRING = 16
};

typedef struct ParamConstsStructTag {
    float defaultValue;
    char name[MAX_STRING + 1];
} ParamConstantsStruct;

typedef struct ParamDynamicDataStructTag {
    float value;
    char displayValue[MAX_STRING];
} ParamDynamicDataStruct;


class UltraWhorldFFGL : public CFreeFrameGLPlugin, CMainFrame
{
public:
	UltraWhorldFFGL();
    virtual ~UltraWhorldFFGL() {}
    
#define FFPARM(tag, defval, name) PARAM_##tag,
	enum {
#include "FFParmDef.h"
		NUM_PARAMS
	};
	enum {
		NUM_INPUTS = 1,
		MAX_STRING = 16
	};
    
	///////////////////////////////////////////////////
	// FreeFrameGL plugin methods
	///////////////////////////////////////////////////
	
	DWORD	SetParameter(const SetParameterStruct* pParam);
	DWORD	GetParameter(DWORD dwIndex);
	DWORD	ProcessOpenGL(ProcessOpenGLStruct* pGL);
    DWORD InitGL(const FFGLViewportStruct *vp);
    DWORD DeInitGL();
    virtual DWORD SetTime(double time);
    
	///////////////////////////////////////////////////
	// Factory method
	///////////////////////////////////////////////////
    
	static DWORD __stdcall CreateInstance(CFreeFrameGLPlugin **ppOutInstance)
    {
        *ppOutInstance = new UltraWhorldFFGL();
        if (*ppOutInstance != NULL)
            return FF_SUCCESS;
        return FF_FAIL;
    }
    
protected:
    ParamDynamicDataStruct m_Param[NUM_PARAMS];
	bool	m_Bang[NUM_PARAMS];

    bool IsBang(int ParamIdx, double Value);
    double m_lastTime;
};


