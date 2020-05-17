/*** 
*csarray.h
*
*  Copyright (C) 1992, Microsoft Corporation.  All Rights Reserved.
*  Information Contained Herein Is Proprietary and Confidential.
*
*Purpose:
*  Definition of the CSArray IDispatch test Object. This object use
*  used to test SafeArray remoting support.
*
*Revision History:
*
* [00]	29-Oct-92 bradlo: Created.
*
*Implementation Notes:
*
*****************************************************************************/

#ifdef __cplusplus /* { */

class CSArray : public IUnknown
{
public:
    static HRESULT Create(IUnknown FAR* punkOuter, IUnknown FAR* FAR* ppunk);

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(REFIID riid, void FAR* FAR* ppvObj);
    STDMETHOD_(unsigned long, AddRef)(void);
    STDMETHOD_(unsigned long, Release)(void);

    // ByVal SafeArray methods
#if VBA2
    STDMETHOD(UI1SafeArray)(SAFEARRAY FAR* psa);
#endif //VBA2
    STDMETHOD(I2SafeArray)(SAFEARRAY FAR* psa);
    STDMETHOD(I4SafeArray)(SAFEARRAY FAR* psa);
    STDMETHOD(R4SafeArray)(SAFEARRAY FAR* psa);
    STDMETHOD(R8SafeArray)(SAFEARRAY FAR* psa);
    STDMETHOD(CySafeArray)(SAFEARRAY FAR* psa);
    STDMETHOD(DateSafeArray)(SAFEARRAY FAR* psa);
    STDMETHOD(BstrSafeArray)(SAFEARRAY FAR* psa);
    STDMETHOD(ScodeSafeArray)(SAFEARRAY FAR* psa);
    STDMETHOD(BoolSafeArray)(SAFEARRAY FAR* psa);
    STDMETHOD(VarSafeArray)(SAFEARRAY FAR* psa);

    // ByRef SafeArray methods
#if VBA2
    STDMETHOD(UI1SafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
#endif //VBA2
    STDMETHOD(I2SafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(I4SafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(R4SafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(R8SafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(CySafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(DateSafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(BstrSafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(ScodeSafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(BoolSafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(VarSafeArrayRef)(SAFEARRAY FAR* FAR* ppsa);

    // method redims a byref SafeArray
    STDMETHOD(SafeArrayRedim)(short vt, SAFEARRAY FAR* FAR* ppsa);

    // method that returns a SafeArray
    STDMETHOD_(SAFEARRAY FAR*, I2SafeArrayRet)(VARIANT var);

    // ByRef SafeArray methods where callee erases the array
#if VBA2
    STDMETHOD(UI1SafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
#endif //VBA2
    STDMETHOD(I2SafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(I4SafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(R4SafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(R8SafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(CySafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(DateSafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(BstrSafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(ScodeSafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(BoolSafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(VarSafeArrayErase)(SAFEARRAY FAR* FAR* ppsa);

    // ByRef SafeArray methods where callee allocates the array
#if VBA2
    STDMETHOD(UI1SafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
#endif //VBA2
    STDMETHOD(I2SafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(I4SafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(R4SafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(R8SafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(CySafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(DateSafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(BstrSafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(ScodeSafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(BoolSafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);
    STDMETHOD(VarSafeArrayAlloc)(SAFEARRAY FAR* FAR* ppsa);

protected:

//#ifndef WIN32
    HRESULT CreateDisp();
#if 0
//#else
    HRESULT CreateDispW();
#endif


private:

    CSArray();

    unsigned long m_refs;
    IUnknown FAR* m_punkDisp;    
};

#endif /* } */

/* the following enums are used to build the TypeInfo that describes
 * our IDispatch exposed methods.
 */

// CSArray method indices.
//
enum CSARRAY_METHODS 
{
    IMETH_CSARRAY_QUERYINTERFACE = 0,
    IMETH_CSARRAY_ADDREF,
    IMETH_CSARRAY_RELEASE,

#if VBA2
    IMETH_CSARRAY_UI1SAFEARRAY,
#endif //VBA2
    IMETH_CSARRAY_I2SAFEARRAY,
    IMETH_CSARRAY_I4SAFEARRAY,
    IMETH_CSARRAY_R4SAFEARRAY,
    IMETH_CSARRAY_R8SAFEARRAY,
    IMETH_CSARRAY_CYSAFEARRAY,
    IMETH_CSARRAY_DATESAFEARRAY,
    IMETH_CSARRAY_BSTRSAFEARRAY,
    IMETH_CSARRAY_SCODESAFEARRAY,
    IMETH_CSARRAY_BOOLSAFEARRAY,
    IMETH_CSARRAY_VARSAFEARRAY,

#if VBA2
    IMETH_CSARRAY_UI1SAFEARRAYREF,
#endif //VBA2
    IMETH_CSARRAY_I2SAFEARRAYREF,
    IMETH_CSARRAY_I4SAFEARRAYREF,
    IMETH_CSARRAY_R4SAFEARRAYREF,
    IMETH_CSARRAY_R8SAFEARRAYREF,
    IMETH_CSARRAY_CYSAFEARRAYREF,
    IMETH_CSARRAY_DATESAFEARRAYREF,
    IMETH_CSARRAY_BSTRSAFEARRAYREF,
    IMETH_CSARRAY_SCODESAFEARRAYREF,
    IMETH_CSARRAY_BOOLSAFEARRAYREF,
    IMETH_CSARRAY_VARSAFEARRAYREF,

    IMETH_CSARRAY_SAFEARRAYREDIM,
    IMETH_CSARRAY_I2SAFEARRAYRET,

#if VBA2
    IMETH_CSARRAY_UI1SAFEARRAYERASE,
#endif //VBA2
    IMETH_CSARRAY_I2SAFEARRAYERASE,
    IMETH_CSARRAY_I4SAFEARRAYERASE,
    IMETH_CSARRAY_R4SAFEARRAYERASE,
    IMETH_CSARRAY_R8SAFEARRAYERASE,
    IMETH_CSARRAY_CYSAFEARRAYERASE,
    IMETH_CSARRAY_DATESAFEARRAYERASE,
    IMETH_CSARRAY_BSTRSAFEARRAYERASE,
    IMETH_CSARRAY_SCODESAFEARRAYERASE,
    IMETH_CSARRAY_BOOLSAFEARRAYERASE,
    IMETH_CSARRAY_VARSAFEARRAYERASE,

#if VBA2
    IMETH_CSARRAY_UI1SAFEARRAYALLOC,
#endif //VBA2
    IMETH_CSARRAY_I2SAFEARRAYALLOC,
    IMETH_CSARRAY_I4SAFEARRAYALLOC,
    IMETH_CSARRAY_R4SAFEARRAYALLOC,
    IMETH_CSARRAY_R8SAFEARRAYALLOC,
    IMETH_CSARRAY_CYSAFEARRAYALLOC,
    IMETH_CSARRAY_DATESAFEARRAYALLOC,
    IMETH_CSARRAY_BSTRSAFEARRAYALLOC,
    IMETH_CSARRAY_SCODESAFEARRAYALLOC,
    IMETH_CSARRAY_BOOLSAFEARRAYALLOC,
    IMETH_CSARRAY_VARSAFEARRAYALLOC,

    IMETH_CSARRAY_MAX
};


// CSArray member IDs
//
enum CSARRAY_MEMBER_IDS
{
#if VBA2
    IDMEMBER_CSARRAY_UI1SAFEARRAY = 0,
    IDMEMBER_CSARRAY_I2SAFEARRAY,
#else //VBA2
    IDMEMBER_CSARRAY_I2SAFEARRAY = 0,
#endif //VBA2
    IDMEMBER_CSARRAY_I4SAFEARRAY,
    IDMEMBER_CSARRAY_R4SAFEARRAY,
    IDMEMBER_CSARRAY_R8SAFEARRAY,
    IDMEMBER_CSARRAY_CYSAFEARRAY,
    IDMEMBER_CSARRAY_DATESAFEARRAY,
    IDMEMBER_CSARRAY_BSTRSAFEARRAY,
    IDMEMBER_CSARRAY_SCODESAFEARRAY,
    IDMEMBER_CSARRAY_BOOLSAFEARRAY,
    IDMEMBER_CSARRAY_VARSAFEARRAY,

#if VBA2
    IDMEMBER_CSARRAY_UI1SAFEARRAYREF,
#endif //VBA2
    IDMEMBER_CSARRAY_I2SAFEARRAYREF,
    IDMEMBER_CSARRAY_I4SAFEARRAYREF,
    IDMEMBER_CSARRAY_R4SAFEARRAYREF,
    IDMEMBER_CSARRAY_R8SAFEARRAYREF,
    IDMEMBER_CSARRAY_CYSAFEARRAYREF,
    IDMEMBER_CSARRAY_DATESAFEARRAYREF,
    IDMEMBER_CSARRAY_BSTRSAFEARRAYREF,
    IDMEMBER_CSARRAY_SCODESAFEARRAYREF,
    IDMEMBER_CSARRAY_BOOLSAFEARRAYREF,
    IDMEMBER_CSARRAY_VARSAFEARRAYREF,

    IDMEMBER_CSARRAY_SAFEARRAYREDIM,
    IDMEMBER_CSARRAY_I2SAFEARRAYRET,

#if VBA2
    IDMEMBER_CSARRAY_UI1SAFEARRAYERASE,
#endif //VBA2
    IDMEMBER_CSARRAY_I2SAFEARRAYERASE,
    IDMEMBER_CSARRAY_I4SAFEARRAYERASE,
    IDMEMBER_CSARRAY_R4SAFEARRAYERASE,
    IDMEMBER_CSARRAY_R8SAFEARRAYERASE,
    IDMEMBER_CSARRAY_CYSAFEARRAYERASE,
    IDMEMBER_CSARRAY_DATESAFEARRAYERASE,
    IDMEMBER_CSARRAY_BSTRSAFEARRAYERASE,
    IDMEMBER_CSARRAY_SCODESAFEARRAYERASE,
    IDMEMBER_CSARRAY_BOOLSAFEARRAYERASE,
    IDMEMBER_CSARRAY_VARSAFEARRAYERASE,

#if VBA2
    IDMEMBER_CSARRAY_UI1SAFEARRAYALLOC,
#endif //VBA2
    IDMEMBER_CSARRAY_I2SAFEARRAYALLOC,
    IDMEMBER_CSARRAY_I4SAFEARRAYALLOC,
    IDMEMBER_CSARRAY_R4SAFEARRAYALLOC,
    IDMEMBER_CSARRAY_R8SAFEARRAYALLOC,
    IDMEMBER_CSARRAY_CYSAFEARRAYALLOC,
    IDMEMBER_CSARRAY_DATESAFEARRAYALLOC,
    IDMEMBER_CSARRAY_BSTRSAFEARRAYALLOC,
    IDMEMBER_CSARRAY_SCODESAFEARRAYALLOC,
    IDMEMBER_CSARRAY_BOOLSAFEARRAYALLOC,
    IDMEMBER_CSARRAY_VARSAFEARRAYALLOC,

    IDMEMBER_CSARRAY_MAX
};
