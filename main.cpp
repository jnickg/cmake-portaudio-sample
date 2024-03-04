#include <iostream>

#include <portaudio.h>

int main (int argc, char *argv[]) {
    std::cout << "Initializing PortAudio!" << std::endl;
    auto status = Pa_Initialize();
    if (status != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(status) << std::endl;
        return 1;
    }
    std::cout << "Initialization complete." << std::endl;

    const auto num_devices = Pa_GetDeviceCount();
    if (num_devices < 0) {
        throw std::runtime_error("Failed to get number of devices");
    }
    std::cout << "Detected " << num_devices << " devices through Port Audio!" << std::endl;

    for (PaDeviceIndex i = 0; i < num_devices; ++i) {
        const auto pa_device_info = Pa_GetDeviceInfo(i);
        if (pa_device_info == nullptr) {
            throw std::runtime_error("Failed to get device info");
        }

        std::cout << "Device " << i << ": " << pa_device_info->name << " - Host API: " << Pa_GetHostApiInfo(pa_device_info->hostApi)->name << std::endl;
    }

    std::cout << "Terminating PortAudio and exiting." << std::endl;
    status = Pa_Terminate();
    if (status != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(status) << std::endl;
        return 1;
    }
    return 0;
}