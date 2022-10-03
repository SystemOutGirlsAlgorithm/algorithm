const codeSharp = ["C#", "D#", "F#", "G#", "A#"];
const insteadSharp = ["c", "d", "f", "g", "a"];

const changeCode = (from, to, song) => {
  from.map((f, index) => {
    song = song.replaceAll(f, to[index]);
  });
  return song;
};

const makeMelody = (time, code) => {
  code.includes("#")
    ? (code = changeCode(codeSharp, insteadSharp, code))
    : code;
  if (code.length < time) {
    code = code.repeat(parseInt(time / code.length) + 1);
  }
  code = code.slice(0, time);
  return code;
};

function solution(m, musicinfos) {
  const music = musicinfos.map((el) => {
    const temp = el.split(",");
    const startTime = temp[0].split(":"),
      endTime = temp[1].split(":");
    const time =
      +endTime[0] * 60 + +endTime[1] - (+startTime[0] * 60 + +startTime[1]);
    const song = makeMelody(time, temp[3]);
    return [temp[2], time, song];
  });
  m = changeCode(codeSharp, insteadSharp, m);
  let findMusic = music.filter((el) => el[2].includes(m));
  if (findMusic.length === 0) return "(None)";
  if (findMusic.length === 1) return findMusic[0][0];
  const sortMusic = findMusic.sort((a, b) => b[1] - a[1]);
  if (sortMusic.length === 1) return sortMusic[0][0];
  return findMusic[0][0];
}
