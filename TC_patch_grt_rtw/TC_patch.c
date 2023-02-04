/*
 * TC_patch.c
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

#include "TC_patch.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>
#include "TC_patch_private.h"
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_TC_patch_T TC_patch_DW;

/* External inputs (root inport signals with default storage) */
ExtU_TC_patch_T TC_patch_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TC_patch_T TC_patch_Y;

/* Real-time model */
static RT_MODEL_TC_patch_T TC_patch_M_;
RT_MODEL_TC_patch_T *const TC_patch_M = &TC_patch_M_;
real_T look1_bingcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T frac;
  real_T y;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear Lagrange'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear Lagrange'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    y = (1.0 - frac) * table[iLeft] + table[iLeft + 1U] * frac;
  }

  return y;
}

/* Model step function */
void TC_patch_step(void)
{
  real_T rtb_IProdOut;
  real_T rtb_Sum;
  real_T rtb_Tsamp;
  real_T tmp;
  int8_T tmp_0;
  int8_T tmp_1;

  /* Lookup_n-D: '<Root>/2-D Lookup Table' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/pedal'
   */
  rtb_IProdOut = look1_bingcapw(TC_patch_U.pedal, TC_patch_P.IP_SLIP_TGT_X,
    TC_patch_P.IP_SLIP_TGT, 3U);

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Inport: '<Root>/FL whl'
   *  Inport: '<Root>/FR whl'
   *  Inport: '<Root>/RL whl'
   *  Inport: '<Root>/RR whl'
   *  MinMax: '<Root>/Max'
   *  Sum: '<Root>/Add'
   *  Sum: '<Root>/Sum1'
   */
  rtb_IProdOut -= fmax(fmax(fmax(TC_patch_U.FLwhl, TC_patch_U.FRwhl),
    TC_patch_U.RLwhl), TC_patch_U.RRwhl) - (((TC_patch_U.FLwhl +
    TC_patch_U.FRwhl) + TC_patch_U.RLwhl) + TC_patch_U.RRwhl) *
    TC_patch_P.Gain2_Gain;

  /* SampleTimeMath: '<S33>/Tsamp' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Product: '<S30>/DProd Out'
   *
   * About '<S33>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Tsamp = rtb_IProdOut * TC_patch_P.TC_D * TC_patch_P.Tsamp_WtEt;

  /* Sum: '<S48>/Sum' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Delay: '<S31>/UD'
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  Product: '<S43>/PProd Out'
   *  Sum: '<S31>/Diff'
   */
  rtb_Sum = (rtb_IProdOut * TC_patch_P.TC_P + TC_patch_DW.Integrator_DSTATE) +
    (rtb_Tsamp - TC_patch_DW.UD_DSTATE);

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  RelationalOperator: '<S46>/LowerRelop1'
   *  RelationalOperator: '<S46>/UpperRelop'
   *  Switch: '<S46>/Switch'
   */
  if (rtb_Sum > TC_patch_P.TC_IGA_MAX) {
    /* Outport: '<Root>/TC IGN OUT' */
    TC_patch_Y.TCIGNOUT = TC_patch_P.TC_IGA_MAX;
  } else if (rtb_Sum < TC_patch_P.TC_IGA_MIN) {
    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<Root>/Constant7'
     *  Outport: '<Root>/TC IGN OUT'
     */
    TC_patch_Y.TCIGNOUT = TC_patch_P.TC_IGA_MIN;
  } else {
    /* Outport: '<Root>/TC IGN OUT' incorporates:
     *  Switch: '<S46>/Switch'
     */
    TC_patch_Y.TCIGNOUT = rtb_Sum;
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  RelationalOperator: '<S29>/u_GTE_up'
   *  RelationalOperator: '<S29>/u_GT_lo'
   *  Switch: '<S29>/Switch1'
   */
  if (rtb_Sum >= TC_patch_P.TC_IGA_MAX) {
    tmp = TC_patch_P.TC_IGA_MAX;
  } else if (rtb_Sum > TC_patch_P.TC_IGA_MIN) {
    /* Switch: '<S29>/Switch1' */
    tmp = rtb_Sum;
  } else {
    tmp = TC_patch_P.TC_IGA_MIN;
  }

  /* Sum: '<S29>/Diff' incorporates:
   *  Switch: '<S29>/Switch'
   */
  rtb_Sum -= tmp;

  /* Product: '<S35>/IProd Out' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  rtb_IProdOut *= TC_patch_P.TC_I;

  /* Switch: '<S26>/Switch1' incorporates:
   *  Constant: '<S26>/Clamping_zero'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/Constant2'
   *  RelationalOperator: '<S26>/fix for DT propagation issue'
   */
  if (rtb_Sum > TC_patch_P.Clamping_zero_Value) {
    tmp_0 = TC_patch_P.Constant_Value;
  } else {
    tmp_0 = TC_patch_P.Constant2_Value;
  }

  /* Switch: '<S26>/Switch2' incorporates:
   *  Constant: '<S26>/Clamping_zero'
   *  Constant: '<S26>/Constant3'
   *  Constant: '<S26>/Constant4'
   *  RelationalOperator: '<S26>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > TC_patch_P.Clamping_zero_Value) {
    tmp_1 = TC_patch_P.Constant3_Value;
  } else {
    tmp_1 = TC_patch_P.Constant4_Value;
  }

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Clamping_zero'
   *  Constant: '<S26>/Constant1'
   *  Logic: '<S26>/AND3'
   *  RelationalOperator: '<S26>/Equal1'
   *  RelationalOperator: '<S26>/Relational Operator'
   *  Switch: '<S26>/Switch1'
   *  Switch: '<S26>/Switch2'
   */
  if ((TC_patch_P.Clamping_zero_Value != rtb_Sum) && (tmp_0 == tmp_1)) {
    rtb_IProdOut = TC_patch_P.Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Switch: '<S26>/Switch'
   */
  TC_patch_DW.Integrator_DSTATE += TC_patch_P.Integrator_gainval * rtb_IProdOut;
  if (TC_patch_DW.Integrator_DSTATE >=
      TC_patch_P.DiscretePIDController_UpperInte) {
    TC_patch_DW.Integrator_DSTATE = TC_patch_P.DiscretePIDController_UpperInte;
  } else if (TC_patch_DW.Integrator_DSTATE <=
             TC_patch_P.DiscretePIDController_LowerInte) {
    TC_patch_DW.Integrator_DSTATE = TC_patch_P.DiscretePIDController_LowerInte;
  }

  /* End of Update for DiscreteIntegrator: '<S38>/Integrator' */

  /* Update for Delay: '<S31>/UD' */
  TC_patch_DW.UD_DSTATE = rtb_Tsamp;

  /* Matfile logging */
  rt_UpdateTXYLogVars(TC_patch_M->rtwLogInfo, (&TC_patch_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(TC_patch_M)!=-1) &&
        !((rtmGetTFinal(TC_patch_M)-TC_patch_M->Timing.taskTime0) >
          TC_patch_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(TC_patch_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TC_patch_M->Timing.clockTick0)) {
    ++TC_patch_M->Timing.clockTickH0;
  }

  TC_patch_M->Timing.taskTime0 = TC_patch_M->Timing.clockTick0 *
    TC_patch_M->Timing.stepSize0 + TC_patch_M->Timing.clockTickH0 *
    TC_patch_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void TC_patch_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)TC_patch_M, 0,
                sizeof(RT_MODEL_TC_patch_T));
  rtmSetTFinal(TC_patch_M, 12.0);
  TC_patch_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    TC_patch_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(TC_patch_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(TC_patch_M->rtwLogInfo, (NULL));
    rtliSetLogT(TC_patch_M->rtwLogInfo, "tout");
    rtliSetLogX(TC_patch_M->rtwLogInfo, "");
    rtliSetLogXFinal(TC_patch_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(TC_patch_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(TC_patch_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(TC_patch_M->rtwLogInfo, 0);
    rtliSetLogDecimation(TC_patch_M->rtwLogInfo, 1);
    rtliSetLogY(TC_patch_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(TC_patch_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(TC_patch_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&TC_patch_DW, 0,
                sizeof(DW_TC_patch_T));

  /* external inputs */
  (void)memset(&TC_patch_U, 0, sizeof(ExtU_TC_patch_T));

  /* external outputs */
  TC_patch_Y.TCIGNOUT = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(TC_patch_M->rtwLogInfo, 0.0, rtmGetTFinal
    (TC_patch_M), TC_patch_M->Timing.stepSize0, (&rtmGetErrorStatus(TC_patch_M)));

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
  TC_patch_DW.Integrator_DSTATE = TC_patch_P.DiscretePIDController_InitialCo;

  /* InitializeConditions for Delay: '<S31>/UD' */
  TC_patch_DW.UD_DSTATE = TC_patch_P.DiscretePIDController_Different;
}

/* Model terminate function */
void TC_patch_terminate(void)
{
  /* (no terminate code required) */
}
