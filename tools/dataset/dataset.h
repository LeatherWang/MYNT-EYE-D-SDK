#ifndef MYNTEYE_D1000_TOOLS_DATASET_H_
#define MYNTEYE_D1000_TOOLS_DATASET_H_

#include <fstream>
#include <memory>
#include <string>

#include "public.h"
#include "mynteye.h"
#include "camera.h"

namespace d1000_tools {

  class Dataset {
    public:
      struct Writer {
        std::ofstream ofs;
        std::string outdir;
        std::string outfile;
      };

      using writer_t = std::shared_ptr<Writer>;

      explicit Dataset(std::string outdir);
      virtual ~Dataset();

      void SaveMotionData(const mynteye::MotionData &data);
      void SaveStreamData(const mynteye::MotionData &data);

    private:
      writer_t GetMotionWriter();
      writer_t GetStreamWriter();

      std::string outdir_;

      writer_t motion_writer_;
      writer_t stream_writer_;
      std::size_t motion_count_;
      std::size_t stream_count_;
  };

} // namespace d1000-tools

#endif // MYNTEYE_D1000_TOOLS_DATASET_H_
