/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2019, Google Inc.
 *
 * controls ID list
 *
 * This file is auto-generated. Do not edit.
 */

#include <libcamera/control_ids.h>
#include <libcamera/controls.h>

/**
 * \file control_ids.h
 * \brief Camera controls identifiers
 */

namespace libcamera {

/**
 * \brief Namespace for libcamera controls
 */
namespace controls {

/**
 * \var AeEnable
 * \brief Enable or disable the AEGC algorithm. When this control is set to true,
 * both ExposureTimeMode and AnalogueGainMode are set to auto, and if this
 * control is set to false then both are set to manual.
 *
 * If ExposureTimeMode or AnalogueGainMode are also set in the same
 * request as AeEnable, then the modes supplied by ExposureTimeMode or
 * AnalogueGainMode will take precedence.
 *
 * \sa ExposureTimeMode AnalogueGainMode
 */

/**
 * \enum AeStateEnum
 * \brief Supported AeState values
 *
 * \var AeStateIdle
 * \brief The AEGC algorithm is inactive.
 *
 * This state is returned when both AnalogueGainMode and
 * ExposureTimeMode are set to Manual and the algorithm is not
 * actively computing any value.
 *
 * \var AeStateSearching
 * \brief The AEGC algorithm is actively computing new values, for either the
 * exposure time or the analogue gain, but has not converged to a
 * stable result yet.
 *
 * This state is returned if at least one of AnalogueGainMode or
 * ExposureTimeMode is auto and the algorithm hasn't converged yet.
 *
 * The AEGC algorithm converges once stable values are computed for
 * all of the controls set to be computed in Auto mode. Once the
 * algorithm converges the state is moved to AeStateConverged.
 *
 * \var AeStateConverged
 * \brief The AEGC algorithm has converged.
 *
 * This state is returned if at least one of AnalogueGainMode or
 * ExposureTimeMode is Auto, and the AEGC algorithm has converged to a
 * stable value.
 *
 * If the measurements move too far away from the convergence point
 * then the AEGC algorithm might start adjusting again, in which case
 * the state is moved to AeStateSearching.
 */

/**
 * \var AeStateValues
 * \brief List of all AeState supported values
 */

/**
 * \var AeStateNameValueMap
 * \brief Map of all AeState supported value names (in std::string format) to value
 */

/**
 * \var AeState
 * \brief Report the AEGC algorithm state.
 *
 * The AEGC algorithm computes the exposure time and the analogue gain
 * to be applied to the image sensor.
 *
 * The AEGC algorithm behaviour is controlled by the ExposureTimeMode and
 * AnalogueGainMode controls, which allow applications to decide how
 * the exposure time and gain are computed, in Auto or Manual mode,
 * independently from one another.
 *
 * The AeState control reports the AEGC algorithm state through a single
 * value and describes it as a single computation block which computes
 * both the exposure time and the analogue gain values.
 *
 * When both the exposure time and analogue gain values are configured to
 * be in Manual mode, the AEGC algorithm is quiescent and does not actively
 * compute any value and the AeState control will report AeStateIdle.
 *
 * When at least the exposure time or analogue gain are configured to be
 * computed by the AEGC algorithm, the AeState control will report if the
 * algorithm has converged to stable values for all of the controls set
 * to be computed in Auto mode.
 *
 * \sa AnalogueGainMode
 * \sa ExposureTimeMode
 */

/**
 * \enum AeMeteringModeEnum
 * \brief Supported AeMeteringMode values
 *
 * \var MeteringCentreWeighted
 * \brief Centre-weighted metering mode.
 *
 * \var MeteringSpot
 * \brief Spot metering mode.
 *
 * \var MeteringMatrix
 * \brief Matrix metering mode.
 *
 * \var MeteringCustom
 * \brief Custom metering mode.
 */

/**
 * \var AeMeteringModeValues
 * \brief List of all AeMeteringMode supported values
 */

/**
 * \var AeMeteringModeNameValueMap
 * \brief Map of all AeMeteringMode supported value names (in std::string format) to value
 */

/**
 * \var AeMeteringMode
 * \brief Specify a metering mode for the AE algorithm to use.
 *
 * The metering modes determine which parts of the image are used to
 * determine the scene brightness. Metering modes may be platform specific
 * and not all metering modes may be supported.
 */

/**
 * \enum AeConstraintModeEnum
 * \brief Supported AeConstraintMode values
 *
 * \var ConstraintNormal
 * \brief Default constraint mode.
 *
 * This mode aims to balance the exposure of different parts of the
 * image so as to reach a reasonable average level. However, highlights
 * in the image may appear over-exposed and lowlights may appear
 * under-exposed.
 *
 * \var ConstraintHighlight
 * \brief Highlight constraint mode.
 *
 * This mode adjusts the exposure levels in order to try and avoid
 * over-exposing the brightest parts (highlights) of an image.
 * Other non-highlight parts of the image may appear under-exposed.
 *
 * \var ConstraintShadows
 * \brief Shadows constraint mode.
 *
 * This mode adjusts the exposure levels in order to try and avoid
 * under-exposing the dark parts (shadows) of an image. Other normally
 * exposed parts of the image may appear over-exposed.
 *
 * \var ConstraintCustom
 * \brief Custom constraint mode.
 */

/**
 * \var AeConstraintModeValues
 * \brief List of all AeConstraintMode supported values
 */

/**
 * \var AeConstraintModeNameValueMap
 * \brief Map of all AeConstraintMode supported value names (in std::string format) to value
 */

/**
 * \var AeConstraintMode
 * \brief Specify a constraint mode for the AE algorithm to use.
 *
 * The constraint modes determine how the measured scene brightness is
 * adjusted to reach the desired target exposure. Constraint modes may be
 * platform specific, and not all constraint modes may be supported.
 */

/**
 * \enum AeExposureModeEnum
 * \brief Supported AeExposureMode values
 *
 * \var ExposureNormal
 * \brief Default exposure mode.
 *
 * \var ExposureShort
 * \brief Exposure mode allowing only short exposure times.
 *
 * \var ExposureLong
 * \brief Exposure mode allowing long exposure times.
 *
 * \var ExposureCustom
 * \brief Custom exposure mode.
 */

/**
 * \var AeExposureModeValues
 * \brief List of all AeExposureMode supported values
 */

/**
 * \var AeExposureModeNameValueMap
 * \brief Map of all AeExposureMode supported value names (in std::string format) to value
 */

/**
 * \var AeExposureMode
 * \brief Specify an exposure mode for the AE algorithm to use.
 *
 * The exposure modes specify how the desired total exposure is divided
 * between the exposure time and the sensor's analogue gain. They are
 * platform specific, and not all exposure modes may be supported.
 *
 * When one of AnalogueGainMode or ExposureTimeMode is set to Manual,
 * the fixed values will override any choices made by AeExposureMode.
 *
 * \sa AnalogueGainMode
 * \sa ExposureTimeMode
 */

/**
 * \var ExposureValue
 * \brief Specify an Exposure Value (EV) parameter.
 *
 * The EV parameter will only be applied if the AE algorithm is currently
 * enabled, that is, at least one of AnalogueGainMode and ExposureTimeMode
 * are in Auto mode.
 *
 * By convention EV adjusts the exposure as log2. For example
 * EV = [-2, -1, -0.5, 0, 0.5, 1, 2] results in an exposure adjustment
 * of [1/4x, 1/2x, 1/sqrt(2)x, 1x, sqrt(2)x, 2x, 4x].
 *
 * \sa AnalogueGainMode
 * \sa ExposureTimeMode
 */

/**
 * \var ExposureTime
 * \brief Exposure time for the frame applied in the sensor device.
 *
 * This value is specified in microseconds.
 *
 * This control will only take effect if ExposureTimeMode is Manual. If
 * this control is set when ExposureTimeMode is Auto, the value will be
 * ignored and will not be retained.
 *
 * When reported in metadata, this control indicates what exposure time
 * was used for the current frame, regardless of ExposureTimeMode.
 * ExposureTimeMode will indicate the source of the exposure time value,
 * whether it came from the AE algorithm or not.
 *
 * \sa AnalogueGain
 * \sa ExposureTimeMode
 */

/**
 * \enum ExposureTimeModeEnum
 * \brief Supported ExposureTimeMode values
 *
 * \var ExposureTimeModeAuto
 * \brief The exposure time will be calculated automatically and set by the
 * AE algorithm.
 *
 * If ExposureTime is set while this mode is active, it will be
 * ignored, and its value will not be retained.
 *
 * When transitioning from Manual to Auto mode, the AEGC should start
 * its adjustments based on the last set manual ExposureTime value.
 *
 * \var ExposureTimeModeManual
 * \brief The exposure time will not be updated by the AE algorithm.
 *
 * When transitioning from Auto to Manual mode, the last computed
 * exposure value is used until a new value is specified through the
 * ExposureTime control. If an ExposureTime value is specified in the
 * same request where the ExposureTimeMode is changed from Auto to
 * Manual, the provided ExposureTime is applied immediately.
 */

/**
 * \var ExposureTimeModeValues
 * \brief List of all ExposureTimeMode supported values
 */

/**
 * \var ExposureTimeModeNameValueMap
 * \brief Map of all ExposureTimeMode supported value names (in std::string format) to value
 */

/**
 * \var ExposureTimeMode
 * \brief Controls the source of the exposure time that is applied to the image
 * sensor.
 *
 * When set to Auto, the AE algorithm computes the exposure time and
 * configures the image sensor accordingly. When set to Manual, the value
 * of the ExposureTime control is used.
 *
 * When transitioning from Auto to Manual mode and no ExposureTime control
 * is provided by the application, the last value computed by the AE
 * algorithm when the mode was Auto will be used. If the ExposureTimeMode
 * was never set to Auto (either because the camera started in Manual mode,
 * or Auto is not supported by the camera), the camera should use a
 * best-effort default value.
 *
 * If ExposureTimeModeManual is supported, the ExposureTime control must
 * also be supported.
 *
 * Cameras that support manual control of the sensor shall support manual
 * mode for both ExposureTimeMode and AnalogueGainMode, and shall expose
 * the ExposureTime and AnalogueGain controls. If the camera also has an
 * AEGC implementation, both ExposureTimeMode and AnalogueGainMode shall
 * support both manual and auto mode. If auto mode is available, it shall
 * be the default mode. These rules do not apply to black box cameras
 * such as UVC cameras, where the available gain and exposure modes are
 * completely dependent on what the device exposes.
 *
 * \par Flickerless exposure mode transitions
 *
 * Applications that wish to transition from ExposureTimeModeAuto to direct
 * control of the exposure time without causing extra flicker can do so by
 * selecting an ExposureTime value as close as possible to the last value
 * computed by the auto exposure algorithm in order to avoid any visible
 * flickering.
 *
 * To select the correct value to use as ExposureTime value, applications
 * should accommodate the natural delay in applying controls caused by the
 * capture pipeline frame depth.
 *
 * When switching to manual exposure mode, applications should not
 * immediately specify an ExposureTime value in the same request where
 * ExposureTimeMode is set to Manual. They should instead wait for the
 * first Request where ExposureTimeMode is reported as
 * ExposureTimeModeManual in the Request metadata, and use the reported
 * ExposureTime to populate the control value in the next Request to be
 * queued to the Camera.
 *
 * The implementation of the auto-exposure algorithm should equally try to
 * minimize flickering and when transitioning from manual exposure mode to
 * auto exposure use the last value provided by the application as starting
 * point.
 *
 * 1. Start with ExposureTimeMode set to Auto
 *
 * 2. Set ExposureTimeMode to Manual
 *
 * 3. Wait for the first completed request that has ExposureTimeMode
 * set to Manual
 *
 * 4. Copy the value reported in ExposureTime into a new request, and
 * submit it
 *
 * 5. Proceed to run manual exposure time as desired
 *
 * \sa ExposureTime
 */

/**
 * \var AnalogueGain
 * \brief Analogue gain value applied in the sensor device.
 *
 * The value of the control specifies the gain multiplier applied to all
 * colour channels. This value cannot be lower than 1.0.
 *
 * This control will only take effect if AnalogueGainMode is Manual. If
 * this control is set when AnalogueGainMode is Auto, the value will be
 * ignored and will not be retained.
 *
 * When reported in metadata, this control indicates what analogue gain
 * was used for the current request, regardless of AnalogueGainMode.
 * AnalogueGainMode will indicate the source of the analogue gain value,
 * whether it came from the AEGC algorithm or not.
 *
 * \sa ExposureTime
 * \sa AnalogueGainMode
 */

/**
 * \enum AnalogueGainModeEnum
 * \brief Supported AnalogueGainMode values
 *
 * \var AnalogueGainModeAuto
 * \brief The analogue gain will be calculated automatically and set by the
 * AEGC algorithm.
 *
 * If AnalogueGain is set while this mode is active, it will be
 * ignored, and it will also not be retained.
 *
 * When transitioning from Manual to Auto mode, the AEGC should start
 * its adjustments based on the last set manual AnalogueGain value.
 *
 * \var AnalogueGainModeManual
 * \brief The analogue gain will not be updated by the AEGC algorithm.
 *
 * When transitioning from Auto to Manual mode, the last computed
 * gain value is used until a new value is specified through the
 * AnalogueGain control. If an AnalogueGain value is specified in the
 * same request where the AnalogueGainMode is changed from Auto to
 * Manual, the provided AnalogueGain is applied immediately.
 */

/**
 * \var AnalogueGainModeValues
 * \brief List of all AnalogueGainMode supported values
 */

/**
 * \var AnalogueGainModeNameValueMap
 * \brief Map of all AnalogueGainMode supported value names (in std::string format) to value
 */

/**
 * \var AnalogueGainMode
 * \brief Controls the source of the analogue gain that is applied to the image
 * sensor.
 *
 * When set to Auto, the AEGC algorithm computes the analogue gain and
 * configures the image sensor accordingly. When set to Manual, the value
 * of the AnalogueGain control is used.
 *
 * When transitioning from Auto to Manual mode and no AnalogueGain control
 * is provided by the application, the last value computed by the AEGC
 * algorithm when the mode was Auto will be used. If the AnalogueGainMode
 * was never set to Auto (either because the camera started in Manual mode,
 * or Auto is not supported by the camera), the camera should use a
 * best-effort default value.
 *
 * If AnalogueGainModeManual is supported, the AnalogueGain control must
 * also be supported.
 *
 * For cameras where we have control over the ISP, both ExposureTimeMode
 * and AnalogueGainMode are expected to support manual mode, and both
 * controls (as well as ExposureTimeMode and AnalogueGain) are expected to
 * be present. If the camera also has an AEGC implementation, both
 * ExposureTimeMode and AnalogueGainMode shall support both manual and
 * auto mode. If auto mode is available, it shall be the default mode.
 * These rules do not apply to black box cameras such as UVC cameras,
 * where the available gain and exposure modes are completely dependent on
 * what the hardware exposes.
 *
 * The same procedure described for performing flickerless transitions in
 * the ExposureTimeMode control documentation can be applied to analogue
 * gain.
 *
 * \sa ExposureTimeMode
 * \sa AnalogueGain
 */

/**
 * \enum AeFlickerModeEnum
 * \brief Supported AeFlickerMode values
 *
 * \var FlickerOff
 * \brief No flicker avoidance is performed.
 *
 * \var FlickerManual
 * \brief Manual flicker avoidance.
 *
 * Suppress flicker effects caused by lighting running with a period
 * specified by the AeFlickerPeriod control.
 * \sa AeFlickerPeriod
 *
 * \var FlickerAuto
 * \brief Automatic flicker period detection and avoidance.
 *
 * The system will automatically determine the most likely value of
 * flicker period, and avoid flicker of this frequency. Once flicker
 * is being corrected, it is implementation dependent whether the
 * system is still able to detect a change in the flicker period.
 * \sa AeFlickerDetected
 */

/**
 * \var AeFlickerModeValues
 * \brief List of all AeFlickerMode supported values
 */

/**
 * \var AeFlickerModeNameValueMap
 * \brief Map of all AeFlickerMode supported value names (in std::string format) to value
 */

/**
 * \var AeFlickerMode
 * \brief Set the flicker avoidance mode for AGC/AEC.
 *
 * The flicker mode determines whether, and how, the AGC/AEC algorithm
 * attempts to hide flicker effects caused by the duty cycle of artificial
 * lighting.
 *
 * Although implementation dependent, many algorithms for "flicker
 * avoidance" work by restricting this exposure time to integer multiples
 * of the cycle period, wherever possible.
 *
 * Implementations may not support all of the flicker modes listed below.
 *
 * By default the system will start in FlickerAuto mode if this is
 * supported, otherwise the flicker mode will be set to FlickerOff.
 */

/**
 * \var AeFlickerPeriod
 * \brief Manual flicker period in microseconds.
 *
 * This value sets the current flicker period to avoid. It is used when
 * AeFlickerMode is set to FlickerManual.
 *
 * To cancel 50Hz mains flicker, this should be set to 10000 (corresponding
 * to 100Hz), or 8333 (120Hz) for 60Hz mains.
 *
 * Setting the mode to FlickerManual when no AeFlickerPeriod has ever been
 * set means that no flicker cancellation occurs (until the value of this
 * control is updated).
 *
 * Switching to modes other than FlickerManual has no effect on the
 * value of the AeFlickerPeriod control.
 *
 * \sa AeFlickerMode
 */

/**
 * \var AeFlickerDetected
 * \brief Flicker period detected in microseconds.
 *
 * The value reported here indicates the currently detected flicker
 * period, or zero if no flicker at all is detected.
 *
 * When AeFlickerMode is set to FlickerAuto, there may be a period during
 * which the value reported here remains zero. Once a non-zero value is
 * reported, then this is the flicker period that has been detected and is
 * now being cancelled.
 *
 * In the case of 50Hz mains flicker, the value would be 10000
 * (corresponding to 100Hz), or 8333 (120Hz) for 60Hz mains flicker.
 *
 * It is implementation dependent whether the system can continue to detect
 * flicker of different periods when another frequency is already being
 * cancelled.
 *
 * \sa AeFlickerMode
 */

/**
 * \var Brightness
 * \brief Specify a fixed brightness parameter.
 *
 * Positive values (up to 1.0) produce brighter images; negative values
 * (up to -1.0) produce darker images and 0.0 leaves pixels unchanged.
 */

/**
 * \var Contrast
 * \brief Specify a fixed contrast parameter.
 *
 * Normal contrast is given by the value 1.0; larger values produce images
 * with more contrast.
 */

/**
 * \var Lux
 * \brief Report an estimate of the current illuminance level in lux.
 *
 * The Lux control can only be returned in metadata.
 */

/**
 * \var AwbEnable
 * \brief Enable or disable the AWB.
 *
 * When AWB is enabled, the algorithm estimates the colour temperature of
 * the scene and computes colour gains and the colour correction matrix
 * automatically. The computed colour temperature, gains and correction
 * matrix are reported in metadata. The corresponding controls are ignored
 * if set in a request.
 *
 * When AWB is disabled, the colour temperature, gains and correction
 * matrix are not updated automatically and can be set manually in
 * requests.
 *
 * \sa ColourCorrectionMatrix
 * \sa ColourGains
 * \sa ColourTemperature
 */

/**
 * \enum AwbModeEnum
 * \brief Supported AwbMode values
 *
 * \var AwbAuto
 * \brief Search over the whole colour temperature range.
 *
 * \var AwbIncandescent
 * \brief Incandescent AWB lamp mode.
 *
 * \var AwbTungsten
 * \brief Tungsten AWB lamp mode.
 *
 * \var AwbFluorescent
 * \brief Fluorescent AWB lamp mode.
 *
 * \var AwbIndoor
 * \brief Indoor AWB lighting mode.
 *
 * \var AwbDaylight
 * \brief Daylight AWB lighting mode.
 *
 * \var AwbCloudy
 * \brief Cloudy AWB lighting mode.
 *
 * \var AwbCustom
 * \brief Custom AWB mode.
 */

/**
 * \var AwbModeValues
 * \brief List of all AwbMode supported values
 */

/**
 * \var AwbModeNameValueMap
 * \brief Map of all AwbMode supported value names (in std::string format) to value
 */

/**
 * \var AwbMode
 * \brief Specify the range of illuminants to use for the AWB algorithm.
 *
 * The modes supported are platform specific, and not all modes may be
 * supported.
 */

/**
 * \var AwbLocked
 * \brief Report the lock status of a running AWB algorithm.
 *
 * If the AWB algorithm is locked the value shall be set to true, if it's
 * converging it shall be set to false. If the AWB algorithm is not
 * running the control shall not be present in the metadata control list.
 *
 * \sa AwbEnable
 */

/**
 * \var ColourGains
 * \brief Pair of gain values for the Red and Blue colour channels, in that
 * order.
 *
 * ColourGains can only be applied in a Request when the AWB is disabled.
 * If ColourGains is set in a request but ColourTemperature is not, the
 * implementation shall calculate and set the ColourTemperature based on
 * the ColourGains.
 *
 * \sa AwbEnable
 * \sa ColourTemperature
 */

/**
 * \var ColourTemperature
 * \brief ColourTemperature of the frame, in kelvin.
 *
 * ColourTemperature can only be applied in a Request when the AWB is
 * disabled.
 *
 * If ColourTemperature is set in a request but ColourGains is not, the
 * implementation shall calculate and set the ColourGains based on the
 * given ColourTemperature. If ColourTemperature is set (either directly,
 * or indirectly by setting ColourGains) but ColourCorrectionMatrix is not,
 * the ColourCorrectionMatrix is updated based on the ColourTemperature.
 *
 * The ColourTemperature used to process the frame is reported in metadata.
 *
 * \sa AwbEnable
 * \sa ColourCorrectionMatrix
 * \sa ColourGains
 */

/**
 * \var Saturation
 * \brief Specify a fixed saturation parameter.
 *
 * Normal saturation is given by the value 1.0; larger values produce more
 * saturated colours; 0.0 produces a greyscale image.
 */

/**
 * \var SensorBlackLevels
 * \brief Reports the sensor black levels used for processing a frame.
 *
 * The values are in the order R, Gr, Gb, B. They are returned as numbers
 * out of a 16-bit pixel range (as if pixels ranged from 0 to 65535). The
 * SensorBlackLevels control can only be returned in metadata.
 */

/**
 * \var Sharpness
 * \brief Intensity of the sharpening applied to the image.
 *
 * A value of 0.0 means no sharpening. The minimum value means
 * minimal sharpening, and shall be 0.0 unless the camera can't
 * disable sharpening completely. The default value shall give a
 * "reasonable" level of sharpening, suitable for most use cases.
 * The maximum value may apply extremely high levels of sharpening,
 * higher than anyone could reasonably want. Negative values are
 * not allowed. Note also that sharpening is not applied to raw
 * streams.
 */

/**
 * \var FocusFoM
 * \brief Reports a Figure of Merit (FoM) to indicate how in-focus the frame is.
 *
 * A larger FocusFoM value indicates a more in-focus frame. This singular
 * value may be based on a combination of statistics gathered from
 * multiple focus regions within an image. The number of focus regions and
 * method of combination is platform dependent. In this respect, it is not
 * necessarily aimed at providing a way to implement a focus algorithm by
 * the application, rather an indication of how in-focus a frame is.
 */

/**
 * \var ColourCorrectionMatrix
 * \brief The 3x3 matrix that converts camera RGB to sRGB within the imaging
 * pipeline.
 *
 * This should describe the matrix that is used after pixels have been
 * white-balanced, but before any gamma transformation. The 3x3 matrix is
 * stored in conventional reading order in an array of 9 floating point
 * values.
 *
 * ColourCorrectionMatrix can only be applied in a Request when the AWB is 
 * disabled.
 *
 * \sa AwbEnable
 * \sa ColourTemperature
 */

/**
 * \var ScalerCrop
 * \brief Sets the image portion that will be scaled to form the whole of
 * the final output image.
 *
 * The (x,y) location of this rectangle is relative to the
 * PixelArrayActiveAreas that is being used. The units remain native
 * sensor pixels, even if the sensor is being used in a binning or
 * skipping mode.
 *
 * This control is only present when the pipeline supports scaling. Its
 * maximum valid value is given by the properties::ScalerCropMaximum
 * property, and the two can be used to implement digital zoom.
 */

/**
 * \var DigitalGain
 * \brief Digital gain value applied during the processing steps applied
 * to the image as captured from the sensor.
 *
 * The global digital gain factor is applied to all the colour channels
 * of the RAW image. Different pipeline models are free to
 * specify how the global gain factor applies to each separate
 * channel.
 *
 * If an imaging pipeline applies digital gain in distinct
 * processing steps, this value indicates their total sum.
 * Pipelines are free to decide how to adjust each processing
 * step to respect the received gain factor and shall report
 * their total value in the request metadata.
 */

/**
 * \var FrameDuration
 * \brief The instantaneous frame duration from start of frame exposure to start
 * of next exposure, expressed in microseconds.
 *
 * This control is meant to be returned in metadata.
 */

/**
 * \var FrameDurationLimits
 * \brief The minimum and maximum (in that order) frame duration, expressed in
 * microseconds.
 *
 * When provided by applications, the control specifies the sensor frame
 * duration interval the pipeline has to use. This limits the largest
 * exposure time the sensor can use. For example, if a maximum frame
 * duration of 33ms is requested (corresponding to 30 frames per second),
 * the sensor will not be able to raise the exposure time above 33ms.
 * A fixed frame duration is achieved by setting the minimum and maximum
 * values to be the same. Setting both values to 0 reverts to using the
 * camera defaults.
 *
 * The maximum frame duration provides the absolute limit to the exposure
 * time computed by the AE algorithm and it overrides any exposure mode
 * setting specified with controls::AeExposureMode. Similarly, when a
 * manual exposure time is set through controls::ExposureTime, it also
 * gets clipped to the limits set by this control. When reported in
 * metadata, the control expresses the minimum and maximum frame durations
 * used after being clipped to the sensor provided frame duration limits.
 *
 * \sa AeExposureMode
 * \sa ExposureTime
 *
 * \todo Define how to calculate the capture frame rate by
 * defining controls to report additional delays introduced by
 * the capture pipeline or post-processing stages (ie JPEG
 * conversion, frame scaling).
 *
 * \todo Provide an explicit definition of default control values, for
 * this and all other controls.
 */

/**
 * \var SensorTemperature
 * \brief Temperature measure from the camera sensor in Celsius.
 *
 * This value is typically obtained by a thermal sensor present on-die or
 * in the camera module. The range of reported temperatures is device
 * dependent.
 *
 * The SensorTemperature control will only be returned in metadata if a
 * thermal sensor is present.
 */

/**
 * \var SensorTimestamp
 * \brief The time when the first row of the image sensor active array is exposed.
 *
 * The timestamp, expressed in nanoseconds, represents a monotonically
 * increasing counter since the system boot time, as defined by the
 * Linux-specific CLOCK_BOOTTIME clock id.
 *
 * The SensorTimestamp control can only be returned in metadata.
 *
 * \todo Define how the sensor timestamp has to be used in the reprocessing
 * use case.
 */

/**
 * \enum AfModeEnum
 * \brief Supported AfMode values
 *
 * \var AfModeManual
 * \brief The AF algorithm is in manual mode.
 *
 * In this mode it will never perform any action nor move the lens of
 * its own accord, but an application can specify the desired lens
 * position using the LensPosition control. The AfState will always
 * report AfStateIdle.
 *
 * If the camera is started in AfModeManual, it will move the focus
 * lens to the position specified by the LensPosition control.
 *
 * This mode is the recommended default value for the AfMode control.
 * External cameras (as reported by the Location property set to
 * CameraLocationExternal) may use a different default value.
 *
 * \var AfModeAuto
 * \brief The AF algorithm is in auto mode.
 *
 * In this mode the algorithm will never move the lens or change state
 * unless the AfTrigger control is used. The AfTrigger control can be
 * used to initiate a focus scan, the results of which will be
 * reported by AfState.
 *
 * If the autofocus algorithm is moved from AfModeAuto to another mode
 * while a scan is in progress, the scan is cancelled immediately,
 * without waiting for the scan to finish.
 *
 * When first entering this mode the AfState will report AfStateIdle.
 * When a trigger control is sent, AfState will report AfStateScanning
 * for a period before spontaneously changing to AfStateFocused or
 * AfStateFailed, depending on the outcome of the scan. It will remain
 * in this state until another scan is initiated by the AfTrigger
 * control. If a scan is cancelled (without changing to another mode),
 * AfState will return to AfStateIdle.
 *
 * \var AfModeContinuous
 * \brief The AF algorithm is in continuous mode.
 *
 * In this mode the lens can re-start a scan spontaneously at any
 * moment, without any user intervention. The AfState still reports
 * whether the algorithm is currently scanning or not, though the
 * application has no ability to initiate or cancel scans, nor to move
 * the lens for itself.
 *
 * However, applications can pause the AF algorithm from continuously
 * scanning by using the AfPause control. This allows video or still
 * images to be captured whilst guaranteeing that the focus is fixed.
 *
 * When set to AfModeContinuous, the system will immediately initiate a
 * scan so AfState will report AfStateScanning, and will settle on one
 * of AfStateFocused or AfStateFailed, depending on the scan result.
 */

/**
 * \var AfModeValues
 * \brief List of all AfMode supported values
 */

/**
 * \var AfModeNameValueMap
 * \brief Map of all AfMode supported value names (in std::string format) to value
 */

/**
 * \var AfMode
 * \brief The mode of the AF (autofocus) algorithm.
 *
 * An implementation may choose not to implement all the modes.
 */

/**
 * \enum AfRangeEnum
 * \brief Supported AfRange values
 *
 * \var AfRangeNormal
 * \brief A wide range of focus distances is scanned.
 *
 * Scanned distances cover all the way from infinity down to close
 * distances, though depending on the implementation, possibly not
 * including the very closest macro positions.
 *
 * \var AfRangeMacro
 * \brief Only close distances are scanned.
 *
 * \var AfRangeFull
 * \brief The full range of focus distances is scanned.
 *
 * This range is similar to AfRangeNormal but includes the very
 * closest macro positions.
 */

/**
 * \var AfRangeValues
 * \brief List of all AfRange supported values
 */

/**
 * \var AfRangeNameValueMap
 * \brief Map of all AfRange supported value names (in std::string format) to value
 */

/**
 * \var AfRange
 * \brief The range of focus distances that is scanned.
 *
 * An implementation may choose not to implement all the options here.
 */

/**
 * \enum AfSpeedEnum
 * \brief Supported AfSpeed values
 *
 * \var AfSpeedNormal
 * \brief Move the lens at its usual speed.
 *
 * \var AfSpeedFast
 * \brief Move the lens more quickly.
 */

/**
 * \var AfSpeedValues
 * \brief List of all AfSpeed supported values
 */

/**
 * \var AfSpeedNameValueMap
 * \brief Map of all AfSpeed supported value names (in std::string format) to value
 */

/**
 * \var AfSpeed
 * \brief Determine whether the AF is to move the lens as quickly as possible or
 * more steadily.
 *
 * For example, during video recording it may be desirable not to move the
 * lens too abruptly, but when in a preview mode (waiting for a still
 * capture) it may be helpful to move the lens as quickly as is reasonably
 * possible.
 */

/**
 * \enum AfMeteringEnum
 * \brief Supported AfMetering values
 *
 * \var AfMeteringAuto
 * \brief Let the AF algorithm decide for itself where it will measure focus.
 *
 * \var AfMeteringWindows
 * \brief Use the rectangles defined by the AfWindows control to measure focus.
 *
 * If no windows are specified the behaviour is platform dependent.
 */

/**
 * \var AfMeteringValues
 * \brief List of all AfMetering supported values
 */

/**
 * \var AfMeteringNameValueMap
 * \brief Map of all AfMetering supported value names (in std::string format) to value
 */

/**
 * \var AfMetering
 * \brief The parts of the image used by the AF algorithm to measure focus.
 */

/**
 * \var AfWindows
 * \brief The focus windows used by the AF algorithm when AfMetering is set to
 * AfMeteringWindows.
 *
 * The units used are pixels within the rectangle returned by the
 * ScalerCropMaximum property.
 *
 * In order to be activated, a rectangle must be programmed with non-zero
 * width and height. Internally, these rectangles are intersected with the
 * ScalerCropMaximum rectangle. If the window becomes empty after this
 * operation, then the window is ignored. If all the windows end up being
 * ignored, then the behaviour is platform dependent.
 *
 * On platforms that support the ScalerCrop control (for implementing
 * digital zoom, for example), no automatic recalculation or adjustment of
 * AF windows is performed internally if the ScalerCrop is changed. If any
 * window lies outside the output image after the scaler crop has been
 * applied, it is up to the application to recalculate them.
 *
 * The details of how the windows are used are platform dependent. We note
 * that when there is more than one AF window, a typical implementation
 * might find the optimal focus position for each one and finally select
 * the window where the focal distance for the objects shown in that part
 * of the image are closest to the camera.
 */

/**
 * \enum AfTriggerEnum
 * \brief Supported AfTrigger values
 *
 * \var AfTriggerStart
 * \brief Start an AF scan.
 *
 * Setting the control to AfTriggerStart is ignored if a scan is in
 * progress.
 *
 * \var AfTriggerCancel
 * \brief Cancel an AF scan.
 *
 * This does not cause the lens to move anywhere else. Ignored if no
 * scan is in progress.
 */

/**
 * \var AfTriggerValues
 * \brief List of all AfTrigger supported values
 */

/**
 * \var AfTriggerNameValueMap
 * \brief Map of all AfTrigger supported value names (in std::string format) to value
 */

/**
 * \var AfTrigger
 * \brief Start an autofocus scan.
 *
 * This control starts an autofocus scan when AfMode is set to AfModeAuto,
 * and is ignored if AfMode is set to AfModeManual or AfModeContinuous. It
 * can also be used to terminate a scan early.
 */

/**
 * \enum AfPauseEnum
 * \brief Supported AfPause values
 *
 * \var AfPauseImmediate
 * \brief Pause the continuous autofocus algorithm immediately.
 *
 * The autofocus algorithm is paused whether or not any kind of scan
 * is underway. AfPauseState will subsequently report
 * AfPauseStatePaused. AfState may report any of AfStateScanning,
 * AfStateFocused or AfStateFailed, depending on the algorithm's state
 * when it received this control.
 *
 * \var AfPauseDeferred
 * \brief Pause the continuous autofocus algorithm at the end of the scan.
 *
 * This is similar to AfPauseImmediate, and if the AfState is
 * currently reporting AfStateFocused or AfStateFailed it will remain
 * in that state and AfPauseState will report AfPauseStatePaused.
 *
 * However, if the algorithm is scanning (AfStateScanning),
 * AfPauseState will report AfPauseStatePausing until the scan is
 * finished, at which point AfState will report one of AfStateFocused
 * or AfStateFailed, and AfPauseState will change to
 * AfPauseStatePaused.
 *
 * \var AfPauseResume
 * \brief Resume continuous autofocus operation.
 *
 * The algorithm starts again from exactly where it left off, and
 * AfPauseState will report AfPauseStateRunning.
 */

/**
 * \var AfPauseValues
 * \brief List of all AfPause supported values
 */

/**
 * \var AfPauseNameValueMap
 * \brief Map of all AfPause supported value names (in std::string format) to value
 */

/**
 * \var AfPause
 * \brief Pause lens movements when in continuous autofocus mode.
 *
 * This control has no effect except when in continuous autofocus mode
 * (AfModeContinuous). It can be used to pause any lens movements while
 * (for example) images are captured. The algorithm remains inactive
 * until it is instructed to resume.
 */

/**
 * \var LensPosition
 * \brief Set and report the focus lens position.
 *
 * This control instructs the lens to move to a particular position and
 * also reports back the position of the lens for each frame.
 *
 * The LensPosition control is ignored unless the AfMode is set to
 * AfModeManual, though the value is reported back unconditionally in all
 * modes.
 *
 * This value, which is generally a non-integer, is the reciprocal of the
 * focal distance in metres, also known as dioptres. That is, to set a
 * focal distance D, the lens position LP is given by
 *
 * \f$LP = \frac{1\mathrm{m}}{D}\f$
 *
 * For example:
 *
 * - 0 moves the lens to infinity.
 * - 0.5 moves the lens to focus on objects 2m away.
 * - 2 moves the lens to focus on objects 50cm away.
 * - And larger values will focus the lens closer.
 *
 * The default value of the control should indicate a good general
 * position for the lens, often corresponding to the hyperfocal distance
 * (the closest position for which objects at infinity are still
 * acceptably sharp). The minimum will often be zero (meaning infinity),
 * and the maximum value defines the closest focus position.
 *
 * \todo Define a property to report the Hyperfocal distance of calibrated
 * lenses.
 */

/**
 * \enum AfStateEnum
 * \brief Supported AfState values
 *
 * \var AfStateIdle
 * \brief The AF algorithm is in manual mode (AfModeManual) or in auto mode
 * (AfModeAuto) and a scan has not yet been triggered, or an
 * in-progress scan was cancelled.
 *
 * \var AfStateScanning
 * \brief The AF algorithm is in auto mode (AfModeAuto), and a scan has been
 * started using the AfTrigger control.
 *
 * The scan can be cancelled by sending AfTriggerCancel at which point
 * the algorithm will either move back to AfStateIdle or, if the scan
 * actually completes before the cancel request is processed, to one
 * of AfStateFocused or AfStateFailed.
 *
 * Alternatively the AF algorithm could be in continuous mode
 * (AfModeContinuous) at which point it may enter this state
 * spontaneously whenever it determines that a rescan is needed.
 *
 * \var AfStateFocused
 * \brief The AF algorithm is in auto (AfModeAuto) or continuous
 * (AfModeContinuous) mode and a scan has completed with the result
 * that the algorithm believes the image is now in focus.
 *
 * \var AfStateFailed
 * \brief The AF algorithm is in auto (AfModeAuto) or continuous
 * (AfModeContinuous) mode and a scan has completed with the result
 * that the algorithm did not find a good focus position.
 */

/**
 * \var AfStateValues
 * \brief List of all AfState supported values
 */

/**
 * \var AfStateNameValueMap
 * \brief Map of all AfState supported value names (in std::string format) to value
 */

/**
 * \var AfState
 * \brief The current state of the AF algorithm.
 *
 * This control reports the current state of the AF algorithm in
 * conjunction with the reported AfMode value and (in continuous AF mode)
 * the AfPauseState value. The possible state changes are described below,
 * though we note the following state transitions that occur when the
 * AfMode is changed.
 *
 * If the AfMode is set to AfModeManual, then the AfState will always
 * report AfStateIdle (even if the lens is subsequently moved). Changing
 * to the AfModeManual state does not initiate any lens movement.
 *
 * If the AfMode is set to AfModeAuto then the AfState will report
 * AfStateIdle. However, if AfModeAuto and AfTriggerStart are sent
 * together then AfState will omit AfStateIdle and move straight to
 * AfStateScanning (and start a scan).
 *
 * If the AfMode is set to AfModeContinuous then the AfState will
 * initially report AfStateScanning.
 */

/**
 * \enum AfPauseStateEnum
 * \brief Supported AfPauseState values
 *
 * \var AfPauseStateRunning
 * \brief Continuous AF is running and the algorithm may restart a scan
 * spontaneously.
 *
 * \var AfPauseStatePausing
 * \brief Continuous AF has been sent an AfPauseDeferred control, and will
 * pause as soon as any in-progress scan completes.
 *
 * When the scan completes, the AfPauseState control will report
 * AfPauseStatePaused. No new scans will be start spontaneously until
 * the AfPauseResume control is sent.
 *
 * \var AfPauseStatePaused
 * \brief Continuous AF is paused.
 *
 * No further state changes or lens movements will occur until the
 * AfPauseResume control is sent.
 */

/**
 * \var AfPauseStateValues
 * \brief List of all AfPauseState supported values
 */

/**
 * \var AfPauseStateNameValueMap
 * \brief Map of all AfPauseState supported value names (in std::string format) to value
 */

/**
 * \var AfPauseState
 * \brief Report whether the autofocus is currently running, paused or pausing.
 *
 * This control is only applicable in continuous (AfModeContinuous) mode,
 * and reports whether the algorithm is currently running, paused or
 * pausing (that is, will pause as soon as any in-progress scan
 * completes).
 *
 * Any change to AfMode will cause AfPauseStateRunning to be reported.
 */

/**
 * \enum HdrModeEnum
 * \brief Supported HdrMode values
 *
 * \var HdrModeOff
 * \brief HDR is disabled.
 *
 * Metadata for this frame will not include the HdrChannel control.
 *
 * \var HdrModeMultiExposureUnmerged
 * \brief Multiple exposures will be generated in an alternating fashion.
 *
 * The multiple exposures will not be merged together and will be
 * returned to the application as they are. Each image will be tagged
 * with the correct HDR channel, indicating what kind of exposure it
 * is. The tag should be the same as in the HdrModeMultiExposure case.
 *
 * The expectation is that an application using this mode would merge
 * the frames to create HDR images for itself if it requires them.
 *
 * \var HdrModeMultiExposure
 * \brief Multiple exposures will be generated and merged to create HDR
 * images.
 *
 * Each image will be tagged with the HDR channel (long, medium or
 * short) that arrived and which caused this image to be output.
 *
 * Systems that use two channels for HDR will return images tagged
 * alternately as the short and long channel. Systems that use three
 * channels for HDR will cycle through the short, medium and long
 * channel before repeating.
 *
 * \var HdrModeSingleExposure
 * \brief Multiple frames all at a single exposure will be used to create HDR
 * images.
 *
 * These images should be reported as all corresponding to the HDR
 * short channel.
 *
 * \var HdrModeNight
 * \brief Multiple frames will be combined to produce "night mode" images.
 *
 * It is up to the implementation exactly which HDR channels it uses,
 * and the images will all be tagged accordingly with the correct HDR
 * channel information.
 */

/**
 * \var HdrModeValues
 * \brief List of all HdrMode supported values
 */

/**
 * \var HdrModeNameValueMap
 * \brief Map of all HdrMode supported value names (in std::string format) to value
 */

/**
 * \var HdrMode
 * \brief Set the mode to be used for High Dynamic Range (HDR) imaging.
 *
 * HDR techniques typically include multiple exposure, image fusion and
 * tone mapping techniques to improve the dynamic range of the resulting
 * images.
 *
 * When using an HDR mode, images are captured with different sets of AGC
 * settings called HDR channels. Channels indicate in particular the type
 * of exposure (short, medium or long) used to capture the raw image,
 * before fusion. Each HDR image is tagged with the corresponding channel
 * using the HdrChannel control.
 *
 * \sa HdrChannel
 */

/**
 * \enum HdrChannelEnum
 * \brief Supported HdrChannel values
 *
 * \var HdrChannelNone
 * \brief This image does not correspond to any of the captures used to create
 * an HDR image.
 *
 * \var HdrChannelShort
 * \brief This is a short exposure image.
 *
 * \var HdrChannelMedium
 * \brief This is a medium exposure image.
 *
 * \var HdrChannelLong
 * \brief This is a long exposure image.
 */

/**
 * \var HdrChannelValues
 * \brief List of all HdrChannel supported values
 */

/**
 * \var HdrChannelNameValueMap
 * \brief Map of all HdrChannel supported value names (in std::string format) to value
 */

/**
 * \var HdrChannel
 * \brief The HDR channel used to capture the frame.
 *
 * This value is reported back to the application so that it can discover
 * whether this capture corresponds to the short or long exposure image
 * (or any other image used by the HDR procedure). An application can
 * monitor the HDR channel to discover when the differently exposed images
 * have arrived.
 *
 * This metadata is only available when an HDR mode has been enabled.
 *
 * \sa HdrMode
 */

/**
 * \var Gamma
 * \brief Specify a fixed gamma value.
 *
 * The default gamma value must be 2.2 which closely mimics sRGB gamma.
 * Note that this is camera gamma, so it is applied as 1.0/gamma.
 */

/**
 * \var DebugMetadataEnable
 * \brief Enable or disable the debug metadata.
 */

/**
 * \var FrameWallClock
 * \brief This timestamp corresponds to the same moment in time as the
 * SensorTimestamp, but is represented as a wall clock time as measured by
 * the CLOCK_REALTIME clock. Like SensorTimestamp, the timestamp value is
 * expressed in nanoseconds.
 *
 * Being a wall clock measurement, it can be used to synchronise timing
 * across different devices.
 *
 * \sa SensorTimestamp
 *
 * The FrameWallClock control can only be returned in metadata.
 */

/**
 * \enum WdrModeEnum
 * \brief Supported WdrMode values
 *
 * \var WdrOff
 * \brief Wdr is disabled.
 *
 * \var WdrLinear
 * \brief Apply a linear global tone mapping curve.
 * A curve with two linear sections is applied. This produces good results at the expense of a slightly artificial look.
 *
 * \var WdrPower
 * \brief Apply a power global tone mapping curve.
 *
 * This curve has high gain values on the dark areas of an image and
 * high compression values on the bright area. It therefore tends to
 * produce noticeable noise artifacts.
 *
 * \var WdrExponential
 * \brief Apply an exponential global tone mapping curve.
 *
 * This curve has lower gain values in dark areas compared to the power
 * curve but produces a more natural look compared to the linear curve.
 * It is therefore the best choice for most scenes.
 *
 * \var WdrHistogramEqualization
 * \brief Apply histogram equalization.
 *
 * This curve preserves most of the information of the image at the
 * expense of a very artificial look. It is therefore best suited for
 * technical analysis.
 */

/**
 * \var WdrModeValues
 * \brief List of all WdrMode supported values
 */

/**
 * \var WdrModeNameValueMap
 * \brief Map of all WdrMode supported value names (in std::string format) to value
 */

/**
 * \var WdrMode
 * \brief Set the WDR mode.
 *
 * The WDR mode is used to select the algorithm used for global tone
 * mapping. It will automatically reduce the exposure time of the sensor
 * so that there are only a small number of saturated pixels in the image.
 * The algorithm then compensates for the loss of brightness by applying a
 * global tone mapping curve to the image.
 */

/**
 * \var WdrStrength
 * \brief Specify the strength of the wdr algorithm. The exact meaning of this
 * value is specific to the algorithm in use. Usually a value of 0 means no
 * global tone mapping is applied. A values of 1 is the default value and
 * the correct value for most scenes. A value above 1 increases the global
 * tone mapping effect and can lead to unrealistic image effects.
 */

/**
 * \var WdrMaxBrightPixels
 * \brief Percentage of allowed (nearly) saturated pixels. The WDR algorithm
 * reduces the WdrExposureValue until the amount of pixels that are close
 * to saturation is lower than this value.
 */

/**
 * \brief Namespace for draft controls
 */
namespace draft {

/**
 * \enum AePrecaptureTriggerEnum
 * \brief Supported AePrecaptureTrigger values
 *
 * \var AePrecaptureTriggerIdle
 * \brief The trigger is idle.
 *
 * \var AePrecaptureTriggerStart
 * \brief The pre-capture AE metering is started by the camera.
 *
 * \var AePrecaptureTriggerCancel
 * \brief The camera will cancel any active or completed metering sequence.
 * The AE algorithm is reset to its initial state.
 */

/**
 * \var AePrecaptureTriggerValues
 * \brief List of all AePrecaptureTrigger supported values
 */

/**
 * \var AePrecaptureTriggerNameValueMap
 * \brief Map of all AePrecaptureTrigger supported value names (in std::string format) to value
 */

/**
 * \var AePrecaptureTrigger
 * \brief Control for AE metering trigger. Currently identical to
 * ANDROID_CONTROL_AE_PRECAPTURE_TRIGGER.
 *
 * Whether the camera device will trigger a precapture metering sequence
 * when it processes this request.
 */

/**
 * \enum NoiseReductionModeEnum
 * \brief Supported NoiseReductionMode values
 *
 * \var NoiseReductionModeOff
 * \brief No noise reduction is applied
 *
 * \var NoiseReductionModeFast
 * \brief Noise reduction is applied without reducing the frame rate.
 *
 * \var NoiseReductionModeHighQuality
 * \brief High quality noise reduction at the expense of frame rate.
 *
 * \var NoiseReductionModeMinimal
 * \brief Minimal noise reduction is applied without reducing the frame rate.
 *
 * \var NoiseReductionModeZSL
 * \brief Noise reduction is applied at different levels to different streams.
 */

/**
 * \var NoiseReductionModeValues
 * \brief List of all NoiseReductionMode supported values
 */

/**
 * \var NoiseReductionModeNameValueMap
 * \brief Map of all NoiseReductionMode supported value names (in std::string format) to value
 */

/**
 * \var NoiseReductionMode
 * \brief Control to select the noise reduction algorithm mode. Currently
 * identical to ANDROID_NOISE_REDUCTION_MODE.
 *
 *  Mode of operation for the noise reduction algorithm.
 */

/**
 * \enum ColorCorrectionAberrationModeEnum
 * \brief Supported ColorCorrectionAberrationMode values
 *
 * \var ColorCorrectionAberrationOff
 * \brief No aberration correction is applied.
 *
 * \var ColorCorrectionAberrationFast
 * \brief Aberration correction will not slow down the frame rate.
 *
 * \var ColorCorrectionAberrationHighQuality
 * \brief High quality aberration correction which might reduce the frame
 * rate.
 */

/**
 * \var ColorCorrectionAberrationModeValues
 * \brief List of all ColorCorrectionAberrationMode supported values
 */

/**
 * \var ColorCorrectionAberrationModeNameValueMap
 * \brief Map of all ColorCorrectionAberrationMode supported value names (in std::string format) to value
 */

/**
 * \var ColorCorrectionAberrationMode
 * \brief Control to select the color correction aberration mode. Currently
 * identical to ANDROID_COLOR_CORRECTION_ABERRATION_MODE.
 *
 *  Mode of operation for the chromatic aberration correction algorithm.
 */

/**
 * \enum AwbStateEnum
 * \brief Supported AwbState values
 *
 * \var AwbStateInactive
 * \brief The AWB algorithm is inactive.
 *
 * \var AwbStateSearching
 * \brief The AWB algorithm has not converged yet.
 *
 * \var AwbConverged
 * \brief The AWB algorithm has converged.
 *
 * \var AwbLocked
 * \brief The AWB algorithm is locked.
 */

/**
 * \var AwbStateValues
 * \brief List of all AwbState supported values
 */

/**
 * \var AwbStateNameValueMap
 * \brief Map of all AwbState supported value names (in std::string format) to value
 */

/**
 * \var AwbState
 * \brief Control to report the current AWB algorithm state. Currently identical
 * to ANDROID_CONTROL_AWB_STATE.
 *
 *  Current state of the AWB algorithm.
 */

/**
 * \var SensorRollingShutterSkew
 * \brief Control to report the time between the start of exposure of the first
 * row and the start of exposure of the last row. Currently identical to
 * ANDROID_SENSOR_ROLLING_SHUTTER_SKEW
 */

/**
 * \enum LensShadingMapModeEnum
 * \brief Supported LensShadingMapMode values
 *
 * \var LensShadingMapModeOff
 * \brief No lens shading map mode is available.
 *
 * \var LensShadingMapModeOn
 * \brief The lens shading map mode is available.
 */

/**
 * \var LensShadingMapModeValues
 * \brief List of all LensShadingMapMode supported values
 */

/**
 * \var LensShadingMapModeNameValueMap
 * \brief Map of all LensShadingMapMode supported value names (in std::string format) to value
 */

/**
 * \var LensShadingMapMode
 * \brief Control to report if the lens shading map is available. Currently
 * identical to ANDROID_STATISTICS_LENS_SHADING_MAP_MODE.
 */

/**
 * \var PipelineDepth
 * \brief Specifies the number of pipeline stages the frame went through from when
 * it was exposed to when the final completed result was available to the
 * framework. Always less than or equal to PipelineMaxDepth. Currently
 * identical to ANDROID_REQUEST_PIPELINE_DEPTH.
 *
 * The typical value for this control is 3 as a frame is first exposed,
 * captured and then processed in a single pass through the ISP. Any
 * additional processing step performed after the ISP pass (in example face
 * detection, additional format conversions etc) count as an additional
 * pipeline stage.
 */

/**
 * \var MaxLatency
 * \brief The maximum number of frames that can occur after a request (different
 * than the previous) has been submitted, and before the result's state
 * becomes synchronized. A value of -1 indicates unknown latency, and 0
 * indicates per-frame control. Currently identical to
 * ANDROID_SYNC_MAX_LATENCY.
 */

/**
 * \enum TestPatternModeEnum
 * \brief Supported TestPatternMode values
 *
 * \var TestPatternModeOff
 * \brief No test pattern mode is used. The camera device returns frames from
 * the image sensor.
 *
 * \var TestPatternModeSolidColor
 * \brief Each pixel in [R, G_even, G_odd, B] is replaced by its respective
 * color channel provided in test pattern data.
 * \todo Add control for test pattern data.
 *
 * \var TestPatternModeColorBars
 * \brief All pixel data is replaced with an 8-bar color pattern. The vertical
 * bars (left-to-right) are as follows; white, yellow, cyan, green,
 * magenta, red, blue and black. Each bar should take up 1/8 of the
 * sensor pixel array width. When this is not possible, the bar size
 * should be rounded down to the nearest integer and the pattern can
 * repeat on the right side. Each bar's height must always take up the
 * full sensor pixel array height.
 *
 * \var TestPatternModeColorBarsFadeToGray
 * \brief The test pattern is similar to TestPatternModeColorBars,
 * except that each bar should start at its specified color at the top
 * and fade to gray at the bottom. Furthermore each bar is further
 * subdevided into a left and right half. The left half should have a
 * smooth gradient, and the right half should have a quantized
 * gradient. In particular, the right half's should consist of blocks
 * of the same color for 1/16th active sensor pixel array width. The
 * least significant bits in the quantized gradient should be copied
 * from the most significant bits of the smooth gradient. The height of
 * each bar should always be a multiple of 128. When this is not the
 * case, the pattern should repeat at the bottom of the image.
 *
 * \var TestPatternModePn9
 * \brief All pixel data is replaced by a pseudo-random sequence generated
 * from a PN9 512-bit sequence (typically implemented in hardware with
 * a linear feedback shift register). The generator should be reset at
 * the beginning of each frame, and thus each subsequent raw frame with
 * this test pattern should be exactly the same as the last.
 *
 * \var TestPatternModeCustom1
 * \brief The first custom test pattern. All custom patterns that are
 * available only on this camera device are at least this numeric
 * value. All of the custom test patterns will be static (that is the
 * raw image must not vary from frame to frame).
 */

/**
 * \var TestPatternModeValues
 * \brief List of all TestPatternMode supported values
 */

/**
 * \var TestPatternModeNameValueMap
 * \brief Map of all TestPatternMode supported value names (in std::string format) to value
 */

/**
 * \var TestPatternMode
 * \brief Control to select the test pattern mode. Currently identical to
 * ANDROID_SENSOR_TEST_PATTERN_MODE.
 */

/**
 * \enum FaceDetectModeEnum
 * \brief Supported FaceDetectMode values
 *
 * \var FaceDetectModeOff
 * \brief Pipeline doesn't perform face detection and doesn't report any
 * control related to face detection.
 *
 * \var FaceDetectModeSimple
 * \brief Pipeline performs face detection and reports the
 * FaceDetectFaceRectangles and FaceDetectFaceScores controls for each
 * detected face. FaceDetectFaceLandmarks and FaceDetectFaceIds are
 * optional.
 *
 * \var FaceDetectModeFull
 * \brief Pipeline performs face detection and reports all the controls
 * related to face detection including FaceDetectFaceRectangles,
 * FaceDetectFaceScores, FaceDetectFaceLandmarks, and
 * FaceDeteceFaceIds for each detected face.
 */

/**
 * \var FaceDetectModeValues
 * \brief List of all FaceDetectMode supported values
 */

/**
 * \var FaceDetectModeNameValueMap
 * \brief Map of all FaceDetectMode supported value names (in std::string format) to value
 */

/**
 * \var FaceDetectMode
 * \brief Control to select the face detection mode used by the pipeline.
 *
 * Currently identical to ANDROID_STATISTICS_FACE_DETECT_MODE.
 *
 * \sa FaceDetectFaceRectangles
 * \sa FaceDetectFaceScores
 * \sa FaceDetectFaceLandmarks
 * \sa FaceDetectFaceIds
 */

/**
 * \var FaceDetectFaceRectangles
 * \brief Boundary rectangles of the detected faces. The number of values is
 * the number of detected faces.
 *
 * The FaceDetectFaceRectangles control can only be returned in metadata.
 *
 * Currently identical to ANDROID_STATISTICS_FACE_RECTANGLES.
 */

/**
 * \var FaceDetectFaceScores
 * \brief Confidence score of each of the detected faces. The range of score is
 * [0, 100]. The number of values should be the number of faces reported
 * in FaceDetectFaceRectangles.
 *
 * The FaceDetectFaceScores control can only be returned in metadata.
 *
 * Currently identical to ANDROID_STATISTICS_FACE_SCORES.
 */

/**
 * \var FaceDetectFaceLandmarks
 * \brief Array of human face landmark coordinates in format [..., left_eye_i,
 * right_eye_i, mouth_i, left_eye_i+1, ...], with i = index of face. The
 * number of values should be 3 * the number of faces reported in
 * FaceDetectFaceRectangles.
 *
 * The FaceDetectFaceLandmarks control can only be returned in metadata.
 *
 * Currently identical to ANDROID_STATISTICS_FACE_LANDMARKS.
 */

/**
 * \var FaceDetectFaceIds
 * \brief Each detected face is given a unique ID that is valid for as long as the
 * face is visible to the camera device. A face that leaves the field of
 * view and later returns may be assigned a new ID. The number of values
 * should be the number of faces reported in FaceDetectFaceRectangles.
 *
 * The FaceDetectFaceIds control can only be returned in metadata.
 *
 * Currently identical to ANDROID_STATISTICS_FACE_IDS.
 */

} /* namespace draft */

/**
 * \brief Namespace for rpi controls
 */
namespace rpi {

/**
 * \var StatsOutputEnable
 * \brief Toggles the Raspberry Pi IPA to output the hardware generated statistics.
 *
 * When this control is set to true, the IPA outputs a binary dump of the
 * hardware generated statistics through the Request metadata in the
 * Bcm2835StatsOutput control.
 *
 * \sa Bcm2835StatsOutput
 */

/**
 * \var Bcm2835StatsOutput
 * \brief Span of the BCM2835 ISP generated statistics for the current frame.
 *
 * This is sent in the Request metadata if the StatsOutputEnable is set to
 * true.  The statistics struct definition can be found in
 * include/linux/bcm2835-isp.h.
 *
 * \sa StatsOutputEnable
 */

/**
 * \var ScalerCrops
 * \brief An array of rectangles, where each singular value has identical
 * functionality to the ScalerCrop control. This control allows the
 * Raspberry Pi pipeline handler to control individual scaler crops per
 * output stream.
 *
 * The order of rectangles passed into the control must match the order of
 * streams configured by the application. The pipeline handler will only
 * configure crop retangles up-to the number of output streams configured.
 * All subsequent rectangles passed into this control are ignored by the
 * pipeline handler.
 *
 * If both rpi::ScalerCrops and ScalerCrop controls are present in a
 * ControlList, the latter is discarded, and crops are obtained from this
 * control.
 *
 * Note that using different crop rectangles for each output stream with
 * this control is only applicable on the Pi5/PiSP platform. This control
 * should also be considered temporary/draft and will be replaced with
 * official libcamera API support for per-stream controls in the future.
 *
 * \sa ScalerCrop
 */

/**
 * \var PispStatsOutput
 * \brief Span of the PiSP Frontend ISP generated statistics for the current
 * frame. This is sent in the Request metadata if the StatsOutputEnable is
 * set to true. The statistics struct definition can be found in
 * https://github.com/raspberrypi/libpisp/blob/main/src/libpisp/frontend/pisp_statistics.h
 *
 * \sa StatsOutputEnable
 */

/**
 * \enum SyncModeEnum
 * \brief Supported SyncMode values
 *
 * \var SyncModeOff
 * \brief Disable sync mode.
 *
 * \var SyncModeServer
 * \brief Enable sync mode, act as server. The server broadcasts timing
 * messages to any clients that are listening, so that the clients can
 * synchronise their camera frames with the server's.
 *
 * \var SyncModeClient
 * \brief Enable sync mode, act as client. A client listens for any server
 * messages, and arranges for its camera frames to synchronise as
 * closely as possible with the server's. Many clients can listen out
 * for the same server. Clients can also be started ahead of any
 * servers, causing them merely to wait for the server to start.
 */

/**
 * \var SyncModeValues
 * \brief List of all SyncMode supported values
 */

/**
 * \var SyncModeNameValueMap
 * \brief Map of all SyncMode supported value names (in std::string format) to value
 */

/**
 * \var SyncMode
 * \brief Enable or disable camera synchronisation ("sync") mode.
 *
 * When sync mode is enabled, a camera will synchronise frames temporally
 * with other cameras, either attached to the same device or a different
 * one. There should be one "server" device, which broadcasts timing
 * information to one or more "clients". Communication is one-way, from
 * server to clients only, and it is only clients that adjust their frame
 * timings to match the server.
 *
 * Sync mode requires all cameras to be running at (as far as possible) the
 * same fixed framerate. Clients may continue to make adjustments to keep
 * their cameras synchronised with the server for the duration of the
 * session, though any updates after the initial ones should remain small.
 *
 * \sa SyncReady
 * \sa SyncTimer
 * \sa SyncFrames
 */

/**
 * \var SyncReady
 * \brief When using the camera synchronisation algorithm, the server broadcasts
 * timing information to the clients. This also includes the time (some
 * number of frames in the future, called the "ready time") at which the
 * server will signal its controlling application, using this control, to
 * start using the image frames.
 *
 * The client receives the "ready time" from the server, and will signal
 * its application to start using the frames at this same moment.
 *
 * While this control value is false, applications (on both client and
 * server) should continue to wait, and not use the frames.
 *
 * Once this value becomes true, it means that this is the first frame
 * where the server and its clients have agreed that they will both be
 * synchronised and that applications should begin consuming frames.
 * Thereafter, this control will continue to signal the value true for
 * the rest of the session.
 *
 * \sa SyncMode
 * \sa SyncTimer
 * \sa SyncFrames
 */

/**
 * \var SyncTimer
 * \brief This reports the amount of time, in microseconds, until the "ready
 * time", at which the server and client will signal their controlling
 * applications that the frames are now synchronised and should be
 * used. The value may be refined slightly over time, becoming more precise
 * as the "ready time" approaches.
 *
 * Servers always report this value, whereas clients will omit this control
 * until they have received a message from the server that enables them to
 * calculate it.
 *
 * Normally the value will start positive (the "ready time" is in the
 * future), and decrease towards zero, before becoming negative (the "ready
 * time" has elapsed). So there should be just one frame where the timer
 * value is, or is very close to, zero - the one for which the SyncReady
 * control becomes true. At this moment, the value indicates how closely
 * synchronised the client believes it is with the server.
 *
 * But note that if frames are being dropped, then the "near zero" valued
 * frame, or indeed any other, could be skipped. In these cases the timer
 * value allows an application to deduce that this has happened.
 *
 * \sa SyncMode
 * \sa SyncReady
 * \sa SyncFrames
 */

/**
 * \var SyncFrames
 * \brief The number of frames the server should wait, after enabling
 * SyncModeServer, before signalling (via the SyncReady control) that
 * frames should be used. This therefore determines the "ready time" for
 * all synchronised cameras.
 *
 * This control value should be set only for the device that is to act as
 * the server, before or at the same moment at which SyncModeServer is
 * enabled.
 *
 * \sa SyncMode
 * \sa SyncReady
 * \sa SyncTimer
 */

} /* namespace rpi */

/**
 * \brief Namespace for debug controls
 */
namespace debug {

} /* namespace debug */


#ifndef __DOXYGEN__
/*
 * Keep the controls definitions hidden from doxygen as it incorrectly parses
 * them as functions.
 */

extern const Control<bool> AeEnable(AE_ENABLE, "AeEnable", "libcamera", ControlId::Direction::In);

extern const std::array<const ControlValue, 3> AeStateValues = {
	static_cast<int32_t>(AeStateIdle),
	static_cast<int32_t>(AeStateSearching),
	static_cast<int32_t>(AeStateConverged),
};
extern const std::map<std::string, int32_t> AeStateNameValueMap = {
	{ "AeStateIdle", AeStateIdle },
	{ "AeStateSearching", AeStateSearching },
	{ "AeStateConverged", AeStateConverged },
};
extern const Control<int32_t> AeState(AE_STATE, "AeState", "libcamera", ControlId::Direction::Out, AeStateNameValueMap);

extern const std::array<const ControlValue, 4> AeMeteringModeValues = {
	static_cast<int32_t>(MeteringCentreWeighted),
	static_cast<int32_t>(MeteringSpot),
	static_cast<int32_t>(MeteringMatrix),
	static_cast<int32_t>(MeteringCustom),
};
extern const std::map<std::string, int32_t> AeMeteringModeNameValueMap = {
	{ "MeteringCentreWeighted", MeteringCentreWeighted },
	{ "MeteringSpot", MeteringSpot },
	{ "MeteringMatrix", MeteringMatrix },
	{ "MeteringCustom", MeteringCustom },
};
extern const Control<int32_t> AeMeteringMode(AE_METERING_MODE, "AeMeteringMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AeMeteringModeNameValueMap);

extern const std::array<const ControlValue, 4> AeConstraintModeValues = {
	static_cast<int32_t>(ConstraintNormal),
	static_cast<int32_t>(ConstraintHighlight),
	static_cast<int32_t>(ConstraintShadows),
	static_cast<int32_t>(ConstraintCustom),
};
extern const std::map<std::string, int32_t> AeConstraintModeNameValueMap = {
	{ "ConstraintNormal", ConstraintNormal },
	{ "ConstraintHighlight", ConstraintHighlight },
	{ "ConstraintShadows", ConstraintShadows },
	{ "ConstraintCustom", ConstraintCustom },
};
extern const Control<int32_t> AeConstraintMode(AE_CONSTRAINT_MODE, "AeConstraintMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AeConstraintModeNameValueMap);

extern const std::array<const ControlValue, 4> AeExposureModeValues = {
	static_cast<int32_t>(ExposureNormal),
	static_cast<int32_t>(ExposureShort),
	static_cast<int32_t>(ExposureLong),
	static_cast<int32_t>(ExposureCustom),
};
extern const std::map<std::string, int32_t> AeExposureModeNameValueMap = {
	{ "ExposureNormal", ExposureNormal },
	{ "ExposureShort", ExposureShort },
	{ "ExposureLong", ExposureLong },
	{ "ExposureCustom", ExposureCustom },
};
extern const Control<int32_t> AeExposureMode(AE_EXPOSURE_MODE, "AeExposureMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AeExposureModeNameValueMap);

extern const Control<float> ExposureValue(EXPOSURE_VALUE, "ExposureValue", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<int32_t> ExposureTime(EXPOSURE_TIME, "ExposureTime", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const std::array<const ControlValue, 2> ExposureTimeModeValues = {
	static_cast<int32_t>(ExposureTimeModeAuto),
	static_cast<int32_t>(ExposureTimeModeManual),
};
extern const std::map<std::string, int32_t> ExposureTimeModeNameValueMap = {
	{ "ExposureTimeModeAuto", ExposureTimeModeAuto },
	{ "ExposureTimeModeManual", ExposureTimeModeManual },
};
extern const Control<int32_t> ExposureTimeMode(EXPOSURE_TIME_MODE, "ExposureTimeMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, ExposureTimeModeNameValueMap);

extern const Control<float> AnalogueGain(ANALOGUE_GAIN, "AnalogueGain", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const std::array<const ControlValue, 2> AnalogueGainModeValues = {
	static_cast<int32_t>(AnalogueGainModeAuto),
	static_cast<int32_t>(AnalogueGainModeManual),
};
extern const std::map<std::string, int32_t> AnalogueGainModeNameValueMap = {
	{ "AnalogueGainModeAuto", AnalogueGainModeAuto },
	{ "AnalogueGainModeManual", AnalogueGainModeManual },
};
extern const Control<int32_t> AnalogueGainMode(ANALOGUE_GAIN_MODE, "AnalogueGainMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AnalogueGainModeNameValueMap);

extern const std::array<const ControlValue, 3> AeFlickerModeValues = {
	static_cast<int32_t>(FlickerOff),
	static_cast<int32_t>(FlickerManual),
	static_cast<int32_t>(FlickerAuto),
};
extern const std::map<std::string, int32_t> AeFlickerModeNameValueMap = {
	{ "FlickerOff", FlickerOff },
	{ "FlickerManual", FlickerManual },
	{ "FlickerAuto", FlickerAuto },
};
extern const Control<int32_t> AeFlickerMode(AE_FLICKER_MODE, "AeFlickerMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AeFlickerModeNameValueMap);

extern const Control<int32_t> AeFlickerPeriod(AE_FLICKER_PERIOD, "AeFlickerPeriod", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<int32_t> AeFlickerDetected(AE_FLICKER_DETECTED, "AeFlickerDetected", "libcamera", ControlId::Direction::Out);

extern const Control<float> Brightness(BRIGHTNESS, "Brightness", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<float> Contrast(CONTRAST, "Contrast", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<float> Lux(LUX, "Lux", "libcamera", ControlId::Direction::Out);

extern const Control<bool> AwbEnable(AWB_ENABLE, "AwbEnable", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const std::array<const ControlValue, 8> AwbModeValues = {
	static_cast<int32_t>(AwbAuto),
	static_cast<int32_t>(AwbIncandescent),
	static_cast<int32_t>(AwbTungsten),
	static_cast<int32_t>(AwbFluorescent),
	static_cast<int32_t>(AwbIndoor),
	static_cast<int32_t>(AwbDaylight),
	static_cast<int32_t>(AwbCloudy),
	static_cast<int32_t>(AwbCustom),
};
extern const std::map<std::string, int32_t> AwbModeNameValueMap = {
	{ "AwbAuto", AwbAuto },
	{ "AwbIncandescent", AwbIncandescent },
	{ "AwbTungsten", AwbTungsten },
	{ "AwbFluorescent", AwbFluorescent },
	{ "AwbIndoor", AwbIndoor },
	{ "AwbDaylight", AwbDaylight },
	{ "AwbCloudy", AwbCloudy },
	{ "AwbCustom", AwbCustom },
};
extern const Control<int32_t> AwbMode(AWB_MODE, "AwbMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AwbModeNameValueMap);

extern const Control<bool> AwbLocked(AWB_LOCKED, "AwbLocked", "libcamera", ControlId::Direction::Out);

extern const Control<Span<const float, 2>> ColourGains(COLOUR_GAINS, "ColourGains", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<int32_t> ColourTemperature(COLOUR_TEMPERATURE, "ColourTemperature", "libcamera", ControlId::Direction::Out);

extern const Control<float> Saturation(SATURATION, "Saturation", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<Span<const int32_t, 4>> SensorBlackLevels(SENSOR_BLACK_LEVELS, "SensorBlackLevels", "libcamera", ControlId::Direction::Out);

extern const Control<float> Sharpness(SHARPNESS, "Sharpness", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<int32_t> FocusFoM(FOCUS_FO_M, "FocusFoM", "libcamera", ControlId::Direction::Out);

extern const Control<Span<const float, 9>> ColourCorrectionMatrix(COLOUR_CORRECTION_MATRIX, "ColourCorrectionMatrix", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<Rectangle> ScalerCrop(SCALER_CROP, "ScalerCrop", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<float> DigitalGain(DIGITAL_GAIN, "DigitalGain", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<int64_t> FrameDuration(FRAME_DURATION, "FrameDuration", "libcamera", ControlId::Direction::Out);

extern const Control<Span<const int64_t, 2>> FrameDurationLimits(FRAME_DURATION_LIMITS, "FrameDurationLimits", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<float> SensorTemperature(SENSOR_TEMPERATURE, "SensorTemperature", "libcamera", ControlId::Direction::Out);

extern const Control<int64_t> SensorTimestamp(SENSOR_TIMESTAMP, "SensorTimestamp", "libcamera", ControlId::Direction::Out);

extern const std::array<const ControlValue, 3> AfModeValues = {
	static_cast<int32_t>(AfModeManual),
	static_cast<int32_t>(AfModeAuto),
	static_cast<int32_t>(AfModeContinuous),
};
extern const std::map<std::string, int32_t> AfModeNameValueMap = {
	{ "AfModeManual", AfModeManual },
	{ "AfModeAuto", AfModeAuto },
	{ "AfModeContinuous", AfModeContinuous },
};
extern const Control<int32_t> AfMode(AF_MODE, "AfMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AfModeNameValueMap);

extern const std::array<const ControlValue, 3> AfRangeValues = {
	static_cast<int32_t>(AfRangeNormal),
	static_cast<int32_t>(AfRangeMacro),
	static_cast<int32_t>(AfRangeFull),
};
extern const std::map<std::string, int32_t> AfRangeNameValueMap = {
	{ "AfRangeNormal", AfRangeNormal },
	{ "AfRangeMacro", AfRangeMacro },
	{ "AfRangeFull", AfRangeFull },
};
extern const Control<int32_t> AfRange(AF_RANGE, "AfRange", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AfRangeNameValueMap);

extern const std::array<const ControlValue, 2> AfSpeedValues = {
	static_cast<int32_t>(AfSpeedNormal),
	static_cast<int32_t>(AfSpeedFast),
};
extern const std::map<std::string, int32_t> AfSpeedNameValueMap = {
	{ "AfSpeedNormal", AfSpeedNormal },
	{ "AfSpeedFast", AfSpeedFast },
};
extern const Control<int32_t> AfSpeed(AF_SPEED, "AfSpeed", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AfSpeedNameValueMap);

extern const std::array<const ControlValue, 2> AfMeteringValues = {
	static_cast<int32_t>(AfMeteringAuto),
	static_cast<int32_t>(AfMeteringWindows),
};
extern const std::map<std::string, int32_t> AfMeteringNameValueMap = {
	{ "AfMeteringAuto", AfMeteringAuto },
	{ "AfMeteringWindows", AfMeteringWindows },
};
extern const Control<int32_t> AfMetering(AF_METERING, "AfMetering", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, AfMeteringNameValueMap);

extern const Control<Span<const Rectangle>> AfWindows(AF_WINDOWS, "AfWindows", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const std::array<const ControlValue, 2> AfTriggerValues = {
	static_cast<int32_t>(AfTriggerStart),
	static_cast<int32_t>(AfTriggerCancel),
};
extern const std::map<std::string, int32_t> AfTriggerNameValueMap = {
	{ "AfTriggerStart", AfTriggerStart },
	{ "AfTriggerCancel", AfTriggerCancel },
};
extern const Control<int32_t> AfTrigger(AF_TRIGGER, "AfTrigger", "libcamera", ControlId::Direction::In, AfTriggerNameValueMap);

extern const std::array<const ControlValue, 3> AfPauseValues = {
	static_cast<int32_t>(AfPauseImmediate),
	static_cast<int32_t>(AfPauseDeferred),
	static_cast<int32_t>(AfPauseResume),
};
extern const std::map<std::string, int32_t> AfPauseNameValueMap = {
	{ "AfPauseImmediate", AfPauseImmediate },
	{ "AfPauseDeferred", AfPauseDeferred },
	{ "AfPauseResume", AfPauseResume },
};
extern const Control<int32_t> AfPause(AF_PAUSE, "AfPause", "libcamera", ControlId::Direction::In, AfPauseNameValueMap);

extern const Control<float> LensPosition(LENS_POSITION, "LensPosition", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const std::array<const ControlValue, 4> AfStateValues = {
	static_cast<int32_t>(AfStateIdle),
	static_cast<int32_t>(AfStateScanning),
	static_cast<int32_t>(AfStateFocused),
	static_cast<int32_t>(AfStateFailed),
};
extern const std::map<std::string, int32_t> AfStateNameValueMap = {
	{ "AfStateIdle", AfStateIdle },
	{ "AfStateScanning", AfStateScanning },
	{ "AfStateFocused", AfStateFocused },
	{ "AfStateFailed", AfStateFailed },
};
extern const Control<int32_t> AfState(AF_STATE, "AfState", "libcamera", ControlId::Direction::Out, AfStateNameValueMap);

extern const std::array<const ControlValue, 3> AfPauseStateValues = {
	static_cast<int32_t>(AfPauseStateRunning),
	static_cast<int32_t>(AfPauseStatePausing),
	static_cast<int32_t>(AfPauseStatePaused),
};
extern const std::map<std::string, int32_t> AfPauseStateNameValueMap = {
	{ "AfPauseStateRunning", AfPauseStateRunning },
	{ "AfPauseStatePausing", AfPauseStatePausing },
	{ "AfPauseStatePaused", AfPauseStatePaused },
};
extern const Control<int32_t> AfPauseState(AF_PAUSE_STATE, "AfPauseState", "libcamera", ControlId::Direction::Out, AfPauseStateNameValueMap);

extern const std::array<const ControlValue, 5> HdrModeValues = {
	static_cast<int32_t>(HdrModeOff),
	static_cast<int32_t>(HdrModeMultiExposureUnmerged),
	static_cast<int32_t>(HdrModeMultiExposure),
	static_cast<int32_t>(HdrModeSingleExposure),
	static_cast<int32_t>(HdrModeNight),
};
extern const std::map<std::string, int32_t> HdrModeNameValueMap = {
	{ "HdrModeOff", HdrModeOff },
	{ "HdrModeMultiExposureUnmerged", HdrModeMultiExposureUnmerged },
	{ "HdrModeMultiExposure", HdrModeMultiExposure },
	{ "HdrModeSingleExposure", HdrModeSingleExposure },
	{ "HdrModeNight", HdrModeNight },
};
extern const Control<int32_t> HdrMode(HDR_MODE, "HdrMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, HdrModeNameValueMap);

extern const std::array<const ControlValue, 4> HdrChannelValues = {
	static_cast<int32_t>(HdrChannelNone),
	static_cast<int32_t>(HdrChannelShort),
	static_cast<int32_t>(HdrChannelMedium),
	static_cast<int32_t>(HdrChannelLong),
};
extern const std::map<std::string, int32_t> HdrChannelNameValueMap = {
	{ "HdrChannelNone", HdrChannelNone },
	{ "HdrChannelShort", HdrChannelShort },
	{ "HdrChannelMedium", HdrChannelMedium },
	{ "HdrChannelLong", HdrChannelLong },
};
extern const Control<int32_t> HdrChannel(HDR_CHANNEL, "HdrChannel", "libcamera", ControlId::Direction::Out, HdrChannelNameValueMap);

extern const Control<float> Gamma(GAMMA, "Gamma", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<bool> DebugMetadataEnable(DEBUG_METADATA_ENABLE, "DebugMetadataEnable", "libcamera", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<int64_t> FrameWallClock(FRAME_WALL_CLOCK, "FrameWallClock", "libcamera", ControlId::Direction::Out);

extern const std::array<const ControlValue, 5> WdrModeValues = {
	static_cast<int32_t>(WdrOff),
	static_cast<int32_t>(WdrLinear),
	static_cast<int32_t>(WdrPower),
	static_cast<int32_t>(WdrExponential),
	static_cast<int32_t>(WdrHistogramEqualization),
};
extern const std::map<std::string, int32_t> WdrModeNameValueMap = {
	{ "WdrOff", WdrOff },
	{ "WdrLinear", WdrLinear },
	{ "WdrPower", WdrPower },
	{ "WdrExponential", WdrExponential },
	{ "WdrHistogramEqualization", WdrHistogramEqualization },
};
extern const Control<int32_t> WdrMode(WDR_MODE, "WdrMode", "libcamera", ControlId::Direction::In | ControlId::Direction::Out, WdrModeNameValueMap);

extern const Control<float> WdrStrength(WDR_STRENGTH, "WdrStrength", "libcamera", ControlId::Direction::In);

extern const Control<float> WdrMaxBrightPixels(WDR_MAX_BRIGHT_PIXELS, "WdrMaxBrightPixels", "libcamera", ControlId::Direction::In);



namespace draft {

extern const std::array<const ControlValue, 3> AePrecaptureTriggerValues = {
	static_cast<int32_t>(AePrecaptureTriggerIdle),
	static_cast<int32_t>(AePrecaptureTriggerStart),
	static_cast<int32_t>(AePrecaptureTriggerCancel),
};
extern const std::map<std::string, int32_t> AePrecaptureTriggerNameValueMap = {
	{ "AePrecaptureTriggerIdle", AePrecaptureTriggerIdle },
	{ "AePrecaptureTriggerStart", AePrecaptureTriggerStart },
	{ "AePrecaptureTriggerCancel", AePrecaptureTriggerCancel },
};
extern const Control<int32_t> AePrecaptureTrigger(AE_PRECAPTURE_TRIGGER, "AePrecaptureTrigger", "draft", ControlId::Direction::In | ControlId::Direction::Out, AePrecaptureTriggerNameValueMap);

extern const std::array<const ControlValue, 5> NoiseReductionModeValues = {
	static_cast<int32_t>(NoiseReductionModeOff),
	static_cast<int32_t>(NoiseReductionModeFast),
	static_cast<int32_t>(NoiseReductionModeHighQuality),
	static_cast<int32_t>(NoiseReductionModeMinimal),
	static_cast<int32_t>(NoiseReductionModeZSL),
};
extern const std::map<std::string, int32_t> NoiseReductionModeNameValueMap = {
	{ "NoiseReductionModeOff", NoiseReductionModeOff },
	{ "NoiseReductionModeFast", NoiseReductionModeFast },
	{ "NoiseReductionModeHighQuality", NoiseReductionModeHighQuality },
	{ "NoiseReductionModeMinimal", NoiseReductionModeMinimal },
	{ "NoiseReductionModeZSL", NoiseReductionModeZSL },
};
extern const Control<int32_t> NoiseReductionMode(NOISE_REDUCTION_MODE, "NoiseReductionMode", "draft", ControlId::Direction::In | ControlId::Direction::Out, NoiseReductionModeNameValueMap);

extern const std::array<const ControlValue, 3> ColorCorrectionAberrationModeValues = {
	static_cast<int32_t>(ColorCorrectionAberrationOff),
	static_cast<int32_t>(ColorCorrectionAberrationFast),
	static_cast<int32_t>(ColorCorrectionAberrationHighQuality),
};
extern const std::map<std::string, int32_t> ColorCorrectionAberrationModeNameValueMap = {
	{ "ColorCorrectionAberrationOff", ColorCorrectionAberrationOff },
	{ "ColorCorrectionAberrationFast", ColorCorrectionAberrationFast },
	{ "ColorCorrectionAberrationHighQuality", ColorCorrectionAberrationHighQuality },
};
extern const Control<int32_t> ColorCorrectionAberrationMode(COLOR_CORRECTION_ABERRATION_MODE, "ColorCorrectionAberrationMode", "draft", ControlId::Direction::In | ControlId::Direction::Out, ColorCorrectionAberrationModeNameValueMap);

extern const std::array<const ControlValue, 4> AwbStateValues = {
	static_cast<int32_t>(AwbStateInactive),
	static_cast<int32_t>(AwbStateSearching),
	static_cast<int32_t>(AwbConverged),
	static_cast<int32_t>(AwbLocked),
};
extern const std::map<std::string, int32_t> AwbStateNameValueMap = {
	{ "AwbStateInactive", AwbStateInactive },
	{ "AwbStateSearching", AwbStateSearching },
	{ "AwbConverged", AwbConverged },
	{ "AwbLocked", AwbLocked },
};
extern const Control<int32_t> AwbState(AWB_STATE, "AwbState", "draft", ControlId::Direction::Out, AwbStateNameValueMap);

extern const Control<int64_t> SensorRollingShutterSkew(SENSOR_ROLLING_SHUTTER_SKEW, "SensorRollingShutterSkew", "draft", ControlId::Direction::Out);

extern const std::array<const ControlValue, 2> LensShadingMapModeValues = {
	static_cast<int32_t>(LensShadingMapModeOff),
	static_cast<int32_t>(LensShadingMapModeOn),
};
extern const std::map<std::string, int32_t> LensShadingMapModeNameValueMap = {
	{ "LensShadingMapModeOff", LensShadingMapModeOff },
	{ "LensShadingMapModeOn", LensShadingMapModeOn },
};
extern const Control<int32_t> LensShadingMapMode(LENS_SHADING_MAP_MODE, "LensShadingMapMode", "draft", ControlId::Direction::In | ControlId::Direction::Out, LensShadingMapModeNameValueMap);

extern const Control<int32_t> PipelineDepth(PIPELINE_DEPTH, "PipelineDepth", "draft", ControlId::Direction::Out);

extern const Control<int32_t> MaxLatency(MAX_LATENCY, "MaxLatency", "draft", ControlId::Direction::Out);

extern const std::array<const ControlValue, 6> TestPatternModeValues = {
	static_cast<int32_t>(TestPatternModeOff),
	static_cast<int32_t>(TestPatternModeSolidColor),
	static_cast<int32_t>(TestPatternModeColorBars),
	static_cast<int32_t>(TestPatternModeColorBarsFadeToGray),
	static_cast<int32_t>(TestPatternModePn9),
	static_cast<int32_t>(TestPatternModeCustom1),
};
extern const std::map<std::string, int32_t> TestPatternModeNameValueMap = {
	{ "TestPatternModeOff", TestPatternModeOff },
	{ "TestPatternModeSolidColor", TestPatternModeSolidColor },
	{ "TestPatternModeColorBars", TestPatternModeColorBars },
	{ "TestPatternModeColorBarsFadeToGray", TestPatternModeColorBarsFadeToGray },
	{ "TestPatternModePn9", TestPatternModePn9 },
	{ "TestPatternModeCustom1", TestPatternModeCustom1 },
};
extern const Control<int32_t> TestPatternMode(TEST_PATTERN_MODE, "TestPatternMode", "draft", ControlId::Direction::In | ControlId::Direction::Out, TestPatternModeNameValueMap);

extern const std::array<const ControlValue, 3> FaceDetectModeValues = {
	static_cast<int32_t>(FaceDetectModeOff),
	static_cast<int32_t>(FaceDetectModeSimple),
	static_cast<int32_t>(FaceDetectModeFull),
};
extern const std::map<std::string, int32_t> FaceDetectModeNameValueMap = {
	{ "FaceDetectModeOff", FaceDetectModeOff },
	{ "FaceDetectModeSimple", FaceDetectModeSimple },
	{ "FaceDetectModeFull", FaceDetectModeFull },
};
extern const Control<int32_t> FaceDetectMode(FACE_DETECT_MODE, "FaceDetectMode", "draft", ControlId::Direction::In | ControlId::Direction::Out, FaceDetectModeNameValueMap);

extern const Control<Span<const Rectangle>> FaceDetectFaceRectangles(FACE_DETECT_FACE_RECTANGLES, "FaceDetectFaceRectangles", "draft", ControlId::Direction::Out);

extern const Control<Span<const uint8_t>> FaceDetectFaceScores(FACE_DETECT_FACE_SCORES, "FaceDetectFaceScores", "draft", ControlId::Direction::Out);

extern const Control<Span<const Point>> FaceDetectFaceLandmarks(FACE_DETECT_FACE_LANDMARKS, "FaceDetectFaceLandmarks", "draft", ControlId::Direction::Out);

extern const Control<Span<const int32_t>> FaceDetectFaceIds(FACE_DETECT_FACE_IDS, "FaceDetectFaceIds", "draft", ControlId::Direction::Out);



} /* namespace draft */

namespace rpi {

extern const Control<bool> StatsOutputEnable(STATS_OUTPUT_ENABLE, "StatsOutputEnable", "rpi", ControlId::Direction::In | ControlId::Direction::Out);

extern const Control<Span<const uint8_t>> Bcm2835StatsOutput(BCM2835_STATS_OUTPUT, "Bcm2835StatsOutput", "rpi", ControlId::Direction::Out);

extern const Control<Span<const Rectangle>> ScalerCrops(SCALER_CROPS, "ScalerCrops", "rpi", ControlId::Direction::Out);

extern const Control<Span<const uint8_t>> PispStatsOutput(PISP_STATS_OUTPUT, "PispStatsOutput", "rpi", ControlId::Direction::Out);

extern const std::array<const ControlValue, 3> SyncModeValues = {
	static_cast<int32_t>(SyncModeOff),
	static_cast<int32_t>(SyncModeServer),
	static_cast<int32_t>(SyncModeClient),
};
extern const std::map<std::string, int32_t> SyncModeNameValueMap = {
	{ "SyncModeOff", SyncModeOff },
	{ "SyncModeServer", SyncModeServer },
	{ "SyncModeClient", SyncModeClient },
};
extern const Control<int32_t> SyncMode(SYNC_MODE, "SyncMode", "rpi", ControlId::Direction::In, SyncModeNameValueMap);

extern const Control<bool> SyncReady(SYNC_READY, "SyncReady", "rpi", ControlId::Direction::Out);

extern const Control<int64_t> SyncTimer(SYNC_TIMER, "SyncTimer", "rpi", ControlId::Direction::Out);

extern const Control<int32_t> SyncFrames(SYNC_FRAMES, "SyncFrames", "rpi", ControlId::Direction::In);



} /* namespace rpi */

namespace debug {



} /* namespace debug */

#endif /* __DOXYGEN__ */

/**
 * \brief List of all supported libcamera controls
 *
 * Unless otherwise stated, all controls are bi-directional, i.e. they can be
 * set through Request::controls() and returned out through Request::metadata().
 */
extern const ControlIdMap controls {
	{ AE_ENABLE, &AeEnable },
	{ AE_STATE, &AeState },
	{ AE_METERING_MODE, &AeMeteringMode },
	{ AE_CONSTRAINT_MODE, &AeConstraintMode },
	{ AE_EXPOSURE_MODE, &AeExposureMode },
	{ EXPOSURE_VALUE, &ExposureValue },
	{ EXPOSURE_TIME, &ExposureTime },
	{ EXPOSURE_TIME_MODE, &ExposureTimeMode },
	{ ANALOGUE_GAIN, &AnalogueGain },
	{ ANALOGUE_GAIN_MODE, &AnalogueGainMode },
	{ AE_FLICKER_MODE, &AeFlickerMode },
	{ AE_FLICKER_PERIOD, &AeFlickerPeriod },
	{ AE_FLICKER_DETECTED, &AeFlickerDetected },
	{ BRIGHTNESS, &Brightness },
	{ CONTRAST, &Contrast },
	{ LUX, &Lux },
	{ AWB_ENABLE, &AwbEnable },
	{ AWB_MODE, &AwbMode },
	{ AWB_LOCKED, &AwbLocked },
	{ COLOUR_GAINS, &ColourGains },
	{ COLOUR_TEMPERATURE, &ColourTemperature },
	{ SATURATION, &Saturation },
	{ SENSOR_BLACK_LEVELS, &SensorBlackLevels },
	{ SHARPNESS, &Sharpness },
	{ FOCUS_FO_M, &FocusFoM },
	{ COLOUR_CORRECTION_MATRIX, &ColourCorrectionMatrix },
	{ SCALER_CROP, &ScalerCrop },
	{ DIGITAL_GAIN, &DigitalGain },
	{ FRAME_DURATION, &FrameDuration },
	{ FRAME_DURATION_LIMITS, &FrameDurationLimits },
	{ SENSOR_TEMPERATURE, &SensorTemperature },
	{ SENSOR_TIMESTAMP, &SensorTimestamp },
	{ AF_MODE, &AfMode },
	{ AF_RANGE, &AfRange },
	{ AF_SPEED, &AfSpeed },
	{ AF_METERING, &AfMetering },
	{ AF_WINDOWS, &AfWindows },
	{ AF_TRIGGER, &AfTrigger },
	{ AF_PAUSE, &AfPause },
	{ LENS_POSITION, &LensPosition },
	{ AF_STATE, &AfState },
	{ AF_PAUSE_STATE, &AfPauseState },
	{ HDR_MODE, &HdrMode },
	{ HDR_CHANNEL, &HdrChannel },
	{ GAMMA, &Gamma },
	{ DEBUG_METADATA_ENABLE, &DebugMetadataEnable },
	{ FRAME_WALL_CLOCK, &FrameWallClock },
	{ WDR_MODE, &WdrMode },
	{ WDR_STRENGTH, &WdrStrength },
	{ WDR_MAX_BRIGHT_PIXELS, &WdrMaxBrightPixels },
	{ draft::AE_PRECAPTURE_TRIGGER, &draft::AePrecaptureTrigger },
	{ draft::NOISE_REDUCTION_MODE, &draft::NoiseReductionMode },
	{ draft::COLOR_CORRECTION_ABERRATION_MODE, &draft::ColorCorrectionAberrationMode },
	{ draft::AWB_STATE, &draft::AwbState },
	{ draft::SENSOR_ROLLING_SHUTTER_SKEW, &draft::SensorRollingShutterSkew },
	{ draft::LENS_SHADING_MAP_MODE, &draft::LensShadingMapMode },
	{ draft::PIPELINE_DEPTH, &draft::PipelineDepth },
	{ draft::MAX_LATENCY, &draft::MaxLatency },
	{ draft::TEST_PATTERN_MODE, &draft::TestPatternMode },
	{ draft::FACE_DETECT_MODE, &draft::FaceDetectMode },
	{ draft::FACE_DETECT_FACE_RECTANGLES, &draft::FaceDetectFaceRectangles },
	{ draft::FACE_DETECT_FACE_SCORES, &draft::FaceDetectFaceScores },
	{ draft::FACE_DETECT_FACE_LANDMARKS, &draft::FaceDetectFaceLandmarks },
	{ draft::FACE_DETECT_FACE_IDS, &draft::FaceDetectFaceIds },
	{ rpi::STATS_OUTPUT_ENABLE, &rpi::StatsOutputEnable },
	{ rpi::BCM2835_STATS_OUTPUT, &rpi::Bcm2835StatsOutput },
	{ rpi::SCALER_CROPS, &rpi::ScalerCrops },
	{ rpi::PISP_STATS_OUTPUT, &rpi::PispStatsOutput },
	{ rpi::SYNC_MODE, &rpi::SyncMode },
	{ rpi::SYNC_READY, &rpi::SyncReady },
	{ rpi::SYNC_TIMER, &rpi::SyncTimer },
	{ rpi::SYNC_FRAMES, &rpi::SyncFrames },
};

} /* namespace controls */

} /* namespace libcamera */