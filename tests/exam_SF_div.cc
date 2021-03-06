#include "exam.h"
#include <cln/sfloat.h>
#include <cln/sfloat_io.h>

static div_test sfloat_div_tests[] = {

{ "0.4319s0", "0.279747s0",
  "1.5439s0" },

{ "0.58111s0", "0.474937s0",
  "1.22354s0" },

{ "0.95817s0", "-0.209396s0",
  "-4.57587s0" },

{ "-0.30497s0", "-0.182861s0",
  "1.66777s0" },

{ "-0.69316s0", "-0.32908s0",
  "2.10635s0" },

{ "-0.87152s0", "0.518326s0",
  "-1.68141s0" },

{ "-0.81208s0", "3.27736s9",
  "-2.47784s-10" },

{ "0.88465s0", "2.15492s9",
  "4.10527s-10" },

{ "-0.96446s0", "8.0971s9",
  "-1.19112s-10" },

{ "-0.65258s0", "-3.98033s9",
  "1.6395s-10" },

{ "0.663826s0", "-7.88726s8",
  "-8.41645s-10" },

{ "-0.31185s0", "4.1015s9",
  "-7.6033s-11" },

{ "-0.89607s0", "-3.887s-14",
  "2.3053s13" },

{ "-0.670135s0", "-5.027s-14",
  "1.33306s13" },

{ "0.94663s0", "-6.153s-14",
  "-1.5385s13" },

{ "-0.76772s0", "4.033s-14",
  "-1.90358s13" },

{ "-0.446358s0", "-1.9017s-13",
  "2.34713s12" },

{ "-0.157814s0", "-2.0401s-13",
  "7.73555s11" },

{ "0.636185s0", "-3.78516s19",
  "-1.68073s-20" },

{ "-0.90556s0", "7.7192s19",
  "-1.17314s-20" },

{ "0.85053s0", "8.3134s19",
  "1.02309s-20" },

{ "-0.3058s0", "3.00674s19",
  "-1.01705s-20" },

{ "0.219429s0", "-8.1184s19",
  "-2.70286s-21" },

{ "0.319603s0", "-2.0739s19",
  "-1.54106s-20" },

{ "0.58943s0", "-5.280s-24",
  "-1.11635s23" },

{ "0.72955s0", "7.852s-24",
  "9.2914s22" },

{ "-0.66327s0", "-3.124s-24",
  "2.12315s23" },

{ "-0.0137558s0", "-7.918s-24",
  "1.73729s21" },

{ "0.35823s0", "5.467s-24",
  "6.55263s22" },

{ "0.93861s0", "9.968s-24",
  "9.4163s22" },

{ "3.83346s9", "0.99782s0",
  "3.84185s9" },

{ "8.7033s9", "-0.81822s0",
  "-1.06369s10" },

{ "3.52326s8", "-0.79994s0",
  "-4.4044s8" },

{ "8.0525s9", "-0.91803s0",
  "-8.7715s9" },

{ "-2.12784s9", "-0.761246s0",
  "2.7952s9" },

{ "1.18805s9", "-0.903534s0",
  "-1.3149s9" },

{ "-6.50556s9", "-5.4642s9",
  "1.19058s0" },

{ "3.3333s8", "1.8341s8",
  "1.81738s0" },

{ "3.70934s9", "9.1957s8",
  "4.03375s0" },

{ "-8.0459s9", "4.5511s9",
  "-1.76791s0" },

{ "3.54982s9", "4.6631s8",
  "7.6126s0" },

{ "-6.27016s9", "-3.42858s9",
  "1.8288s0" },

{ "-4.3213s9", "7.223s-15",
  "-5.98274s23" },

{ "-2.57753s9", "-2.533s-15",
  "1.01759s24" },

{ "3.8858s9", "-4.505s-14",
  "-8.6256s22" },

{ "3.5946s9", "-5.067s-14",
  "-7.0941s22" },

{ "2.94434s9", "8.333s-14",
  "3.53333s22" },

{ "5.6178s9", "-8.241s-14",
  "-6.81694s22" },

{ "4.9591s8", "3.9972s19",
  "1.24064s-11" },

{ "2.4166s9", "-9.2141s19",
  "-2.62272s-11" },

{ "-1.484s9", "2.0281s19",
  "-7.3172s-11" },

{ "2.2339s8", "1.96374s19",
  "1.13758s-11" },

{ "-6.6306s9", "-2.414s19",
  "2.7467s-10" },

{ "9.9114s9", "9.6187s19",
  "1.03043s-10" },

{ "4.4579s9", "5.343s-24",
  "8.3434s32" },

{ "-6.35994s9", "-6.301s-24",
  "1.00936s33" },

{ "5.49677s9", "-1.9306s-25",
  "-2.84717s34" },

{ "-5.007s9", "3.692s-24",
  "-1.35617s33" },

{ "8.6837s9", "-1.6358s-23",
  "-5.3085s32" },

{ "5.5898s9", "-5.435s-24",
  "-1.02849s33" },

{ "-5.042s-14", "0.79081s0",
  "-6.3758s-14" },

{ "-6.231s-14", "0.96946s0",
  "-6.4273s-14" },

{ "6.016s-14", "0.418983s0",
  "1.43587s-13" },

{ "-1.1682s-13", "0.70944s0",
  "-1.64663s-13" },

{ "-1.7485s-13", "0.83207s0",
  "-2.1014s-13" },

{ "7.831s-15", "-0.083374s0",
  "-9.3926s-14" },

{ "3.947s-14", "9.2342s9",
  "4.2744s-24" },

{ "-1.1537s-13", "-6.44075s9",
  "1.79124s-23" },

{ "6.751s-14", "5.8395s8",
  "1.1561s-22" },

{ "-5.026s-14", "7.9677s9",
  "-6.308s-24" },

{ "-1.0105s-13", "-1.71082s9",
  "5.9066s-23" },

{ "-4.996s-14", "9.426s9",
  "-5.30024s-24" },

{ "-6.837s-14", "-3.573s-14",
  "1.91351s0" },

{ "-7.736s-14", "-4.898s-14",
  "1.57942s0" },

{ "3.777s-14", "8.025s-14",
  "0.470657s0" },

{ "-6.239s-14", "8.518s-15",
  "-7.32446s0" },

{ "-7.548s-15", "-4.573s-14",
  "0.165056s0" },

{ "1.6293s-14", "4.712s-14",
  "0.345776s0" },

{ "-4.47s-14", "2.73658s19",
  "-1.63342s-33" },

{ "1.0583s-13", "2.52534s19",
  "4.19073s-33" },

{ "4.351s-15", "2.70326s19",
  "1.60955s-34" },

{ "3.699s-14", "-6.00707s19",
  "-6.1577s-34" },

{ "6.358s-14", "5.18274s19",
  "1.22677s-33" },

{ "-2.971s-14", "6.153s19",
  "-4.8286s-34" },

{ "-4.968s-14", "7.699s-24",
  "-6.4528s9" },

{ "-3.654s-14", "8.434s-24",
  "-4.3325s9" },

{ "-9.276s-14", "-7.079s-24",
  "1.31035s10" },

{ "-4.556s-14", "1.3900s-23",
  "-3.27772s9" },

{ "3.832s-14", "1.55715s-22",
  "2.4609s8" },

{ "1.4186s-13", "1.64482s-21",
  "8.6246s7" },

{ "-7.0974s19", "-0.705536s0",
  "1.00596s20" },

{ "-7.687s19", "-0.241531s0",
  "3.1826s20" },

{ "3.37013s19", "-0.425987s0",
  "-7.9114s19" },

{ "6.56473s19", "-0.60696s0",
  "-1.08158s20" },

{ "4.1598s19", "0.60135s0",
  "6.9175s19" },

{ "8.8312s19", "0.93547s0",
  "9.4404s19" },

{ "2.81357s19", "-2.62832s9",
  "-1.07048s10" },

{ "5.9243s19", "-4.5189s8",
  "-1.311s11" },

{ "-8.3887s19", "9.5761s9",
  "-8.7601s9" },

{ "7.7606s19", "-8.5369s9",
  "-9.0906s9" },

{ "-7.9868s19", "5.0173s9",
  "-1.59186s10" },

{ "7.4128s19", "-6.7781s9",
  "-1.09364s10" },

{ "1.27472s19", "1.1699s-13",
  "1.0896s32" },

{ "2.97578s19", "4.448s-14",
  "6.6901s32" },

{ "7.19416s19", "1.3834s-13",
  "5.20034s32" },

{ "6.61843s19", "-4.268s-14",
  "-1.55071s33" },

{ "2.8579s19", "4.364s-14",
  "6.5488s32" },

{ "8.2451s18", "-6.532s-14",
  "-1.26227s32" },

{ "4.63364s19", "9.4305s19",
  "0.491344s0" },

{ "-1.81999s19", "1.05424s19",
  "-1.72636s0" },

{ "-1.41579s19", "-4.03517s19",
  "0.350864s0" },

{ "-1.88523s18", "-3.3165s18",
  "0.568436s0" },

{ "8.4152s17", "-7.3293s19",
  "-0.0114815s0" },

{ "-8.674s19", "-3.63595s19",
  "2.38562s0" },

{ "-1.64643s-22", "0.78035s0",
  "-2.10986s-22" },

{ "-7.455s-24", "-0.63174s0",
  "1.18009s-23" },

{ "-3.259s-24", "-0.89363s0",
  "3.64694s-24" },

{ "1.5803s-23", "-0.11338s0",
  "-1.39382s-22" },

{ "-3.534s-24", "0.407562s0",
  "-8.6711s-24" },

{ "-7.221s-24", "0.90274s0",
  "-7.999s-24" },

{ "1.0479s-23", "5.66256s8",
  "1.85059s-32" },

{ "1.62856s-21", "-1.9551s9",
  "-8.3298s-31" },

{ "-8.102s-24", "9.7896s9",
  "-8.2761s-34" },

{ "9.693s-24", "-8.777s9",
  "-1.10437s-33" },

{ "8.643s-24", "-1.25557s9",
  "-6.8837s-33" },

{ "3.224s-24", "9.8161s9",
  "3.2844s-34" },

{ "1.06582s-21", "-1.0408s-13",
  "-1.02405s-8" },

{ "1.6738s-23", "9.851s-14",
  "1.69914s-10" },

{ "-1.1514s-23", "-6.509s-14",
  "1.76893s-10" },

{ "9.171s-24", "9.292s-14",
  "9.8698s-11" },

{ "1.8589s-23", "-4.213s-14",
  "-4.4123s-10" },

{ "1.2837s-23", "1.1034s-13",
  "1.16341s-10" },

{ "3.671s-24", "1.0091s-23",
  "0.363792s0" },

{ "-3.373s-24", "-1.7017s-23",
  "0.198214s0" },

{ "-2.0157s-23", "1.0021s-23",
  "-2.01147s0" },

{ "8.041s-24", "-1.3974s-23",
  "-0.575424s0" },

{ "-5.391s-24", "1.1762s-23",
  "-0.458344s0" },

{ "1.7735s-23", "-3.313s-24",
  "-5.3531s0" },

};
