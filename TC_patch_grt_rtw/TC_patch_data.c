/*
 * TC_patch_data.c
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

/* Block parameters (default storage) */
P_TC_patch_T TC_patch_P = {
  /* Variable: IP_SLIP_TGT
   * Referenced by: '<Root>/Constant2'
   */
  { 20.0, 3.0, 3.0, 4.0 },

  /* Variable: IP_SLIP_TGT_X
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 10.0, 60.0, 100.0 },

  /* Variable: TC_D
   * Referenced by: '<Root>/Constant5'
   */
  0.01,

  /* Variable: TC_I
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Variable: TC_IGA_MAX
   * Referenced by: '<Root>/Constant6'
   */
  0.0,

  /* Variable: TC_IGA_MIN
   * Referenced by: '<Root>/Constant7'
   */
  -25.0,

  /* Variable: TC_P
   * Referenced by: '<Root>/Constant3'
   */
  1.3,

  /* Mask Parameter: DiscretePIDController_Different
   * Referenced by: '<S31>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_LowerInte
   * Referenced by: '<S38>/Integrator'
   */
  -10.0,

  /* Mask Parameter: DiscretePIDController_UpperInte
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S26>/Constant1'
   */
  0.0,

  /* Expression: 0.25
   * Referenced by: '<Root>/Gain2'
   */
  0.25,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S38>/Integrator'
   */
  0.02,

  /* Computed Parameter: Tsamp_WtEt
   * Referenced by: '<S33>/Tsamp'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S26>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S26>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S26>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S26>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S26>/Constant4'
   */
  -1
};
