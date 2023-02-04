/*
 * TC_patch.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TC_patch".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Feb  3 21:56:10 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TC_patch_h_
#define RTW_HEADER_TC_patch_h_
#ifndef TC_patch_COMMON_INCLUDES_
#define TC_patch_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* TC_patch_COMMON_INCLUDES_ */

#include "TC_patch_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S38>/Integrator' */
  real_T UD_DSTATE;                    /* '<S31>/UD' */
} DW_TC_patch_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T pedal;                        /* '<Root>/pedal' */
  real_T FLwhl;                        /* '<Root>/FL whl' */
  real_T FRwhl;                        /* '<Root>/FR whl' */
  real_T RLwhl;                        /* '<Root>/RL whl' */
  real_T RRwhl;                        /* '<Root>/RR whl' */
} ExtU_TC_patch_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T TCIGNOUT;                     /* '<Root>/TC IGN OUT' */
} ExtY_TC_patch_T;

/* Parameters (default storage) */
struct P_TC_patch_T_ {
  real_T IP_SLIP_TGT[4];               /* Variable: IP_SLIP_TGT
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T IP_SLIP_TGT_X[4];             /* Variable: IP_SLIP_TGT_X
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T TC_D;                         /* Variable: TC_D
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T TC_I;                         /* Variable: TC_I
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T TC_IGA_MAX;                   /* Variable: TC_IGA_MAX
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T TC_IGA_MIN;                   /* Variable: TC_IGA_MIN
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T TC_P;                         /* Variable: TC_P
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T DiscretePIDController_Different;
                              /* Mask Parameter: DiscretePIDController_Different
                               * Referenced by: '<S31>/UD'
                               */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T DiscretePIDController_LowerInte;
                              /* Mask Parameter: DiscretePIDController_LowerInte
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T DiscretePIDController_UpperInte;
                              /* Mask Parameter: DiscretePIDController_UpperInte
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.25
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S38>/Integrator'
                                        */
  real_T Tsamp_WtEt;                   /* Computed Parameter: Tsamp_WtEt
                                        * Referenced by: '<S33>/Tsamp'
                                        */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S26>/Clamping_zero'
                                        */
  int8_T Constant_Value;               /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S26>/Constant'
                                        */
  int8_T Constant2_Value;              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S26>/Constant2'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S26>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S26>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TC_patch_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_TC_patch_T TC_patch_P;

/* Block states (default storage) */
extern DW_TC_patch_T TC_patch_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_TC_patch_T TC_patch_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TC_patch_T TC_patch_Y;

/* Model entry point functions */
extern void TC_patch_initialize(void);
extern void TC_patch_step(void);
extern void TC_patch_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TC_patch_T *const TC_patch_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TC_patch'
 * '<S1>'   : 'TC_patch/Discrete PID Controller'
 * '<S2>'   : 'TC_patch/Discrete PID Controller/Anti-windup'
 * '<S3>'   : 'TC_patch/Discrete PID Controller/D Gain'
 * '<S4>'   : 'TC_patch/Discrete PID Controller/Filter'
 * '<S5>'   : 'TC_patch/Discrete PID Controller/Filter ICs'
 * '<S6>'   : 'TC_patch/Discrete PID Controller/I Gain'
 * '<S7>'   : 'TC_patch/Discrete PID Controller/Ideal P Gain'
 * '<S8>'   : 'TC_patch/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'TC_patch/Discrete PID Controller/Integrator'
 * '<S10>'  : 'TC_patch/Discrete PID Controller/Integrator ICs'
 * '<S11>'  : 'TC_patch/Discrete PID Controller/N Copy'
 * '<S12>'  : 'TC_patch/Discrete PID Controller/N Gain'
 * '<S13>'  : 'TC_patch/Discrete PID Controller/P Copy'
 * '<S14>'  : 'TC_patch/Discrete PID Controller/Parallel P Gain'
 * '<S15>'  : 'TC_patch/Discrete PID Controller/Reset Signal'
 * '<S16>'  : 'TC_patch/Discrete PID Controller/Saturation'
 * '<S17>'  : 'TC_patch/Discrete PID Controller/Saturation Fdbk'
 * '<S18>'  : 'TC_patch/Discrete PID Controller/Sum'
 * '<S19>'  : 'TC_patch/Discrete PID Controller/Sum Fdbk'
 * '<S20>'  : 'TC_patch/Discrete PID Controller/Tracking Mode'
 * '<S21>'  : 'TC_patch/Discrete PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'TC_patch/Discrete PID Controller/Tsamp - Integral'
 * '<S23>'  : 'TC_patch/Discrete PID Controller/Tsamp - Ngain'
 * '<S24>'  : 'TC_patch/Discrete PID Controller/postSat Signal'
 * '<S25>'  : 'TC_patch/Discrete PID Controller/preSat Signal'
 * '<S26>'  : 'TC_patch/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S27>'  : 'TC_patch/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S28>'  : 'TC_patch/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S29>'  : 'TC_patch/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S30>'  : 'TC_patch/Discrete PID Controller/D Gain/External Parameters'
 * '<S31>'  : 'TC_patch/Discrete PID Controller/Filter/Differentiator'
 * '<S32>'  : 'TC_patch/Discrete PID Controller/Filter/Differentiator/Tsamp'
 * '<S33>'  : 'TC_patch/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S34>'  : 'TC_patch/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S35>'  : 'TC_patch/Discrete PID Controller/I Gain/External Parameters'
 * '<S36>'  : 'TC_patch/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'TC_patch/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'TC_patch/Discrete PID Controller/Integrator/Discrete'
 * '<S39>'  : 'TC_patch/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S40>'  : 'TC_patch/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S41>'  : 'TC_patch/Discrete PID Controller/N Gain/Passthrough'
 * '<S42>'  : 'TC_patch/Discrete PID Controller/P Copy/Disabled'
 * '<S43>'  : 'TC_patch/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S44>'  : 'TC_patch/Discrete PID Controller/Reset Signal/Disabled'
 * '<S45>'  : 'TC_patch/Discrete PID Controller/Saturation/External'
 * '<S46>'  : 'TC_patch/Discrete PID Controller/Saturation/External/Saturation Dynamic'
 * '<S47>'  : 'TC_patch/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S48>'  : 'TC_patch/Discrete PID Controller/Sum/Sum_PID'
 * '<S49>'  : 'TC_patch/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S50>'  : 'TC_patch/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S51>'  : 'TC_patch/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'TC_patch/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S53>'  : 'TC_patch/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'TC_patch/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S55>'  : 'TC_patch/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_TC_patch_h_ */
