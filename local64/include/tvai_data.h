#ifndef TVAI_DATA_H
#define TVAI_DATA_H

#define TVAI_MAX_PARAMETER_COUNT 20
#define TVAI_MAX_OPTIONS_COUNT 5
#define TVAI_PROCESSOR_NAME_SIZE 32
#ifdef __cplusplus
extern "C" {
#endif

    typedef enum {
        FrameTypeNone = 0,
        FrameTypeStart = 1,
        FrameTypeNormal = 2,
        FrameTypeIgnore = 64,
        FrameTypeEnd = 128
    } FrameType;


    typedef enum {
      ModelTypeNone,
      ModelTypeUpscaling = 1,
      ModelTypeFrameInterpolation = 2,
      ModelTypeParameterEstimation = 3,
      ModelTypeCamPoseEstimation = 4,
      ModelTypeStabilization = 5,
      ModelTypeCount
    } ModelType;

    typedef struct {
        int index;
        unsigned int extraThreadCount;
        double maxMemory;
    } DeviceSetting;

    typedef struct {
        char *modelName;
        char processorName[TVAI_PROCESSOR_NAME_SIZE];
        int inputWidth, inputHeight, scale;
        double timebase, framerate;
        DeviceSetting device;
        int canDownloadModel;
    } BasicProcessorInfo;

    typedef struct {
        BasicProcessorInfo basic;
        int outputWidth, outputHeight;
        int frameCount;
        int applyPreflight, applyPostflight;
        char *options[TVAI_MAX_OPTIONS_COUNT];
        float modelParameters[TVAI_MAX_PARAMETER_COUNT];
    } VideoProcessorInfo;


    typedef struct {
        unsigned char *pBuffer;
        int lineSize;
        long long pts;
        long frameNo;
    } TVAIBuffer;

    typedef struct {
        TVAIBuffer input, output;
        FrameType frameType;
        float modelParameters[TVAI_MAX_PARAMETER_COUNT];
    } IOBuffer;

#ifdef __cplusplus
}
#endif

#endif // TVAI_DATA_H
