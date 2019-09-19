/*
 * Tester written by Dr. Lewis. Copyright 2019.
 */
            print("ERROR: No output from student app.", file=sys.stderr)
            sys.exit(1)

        print("STUDENT OUTPUT")
        print("\t----------------------------------")
        print("\t  {}".format(actual))
        print("\t----------------------------------")

        if actual == self._expected[self._test_no]:
            print("CORRECT!")
        else:
            print("INCORRECT...")
            print("  Expected:\t{}".format(self._expected[self._test_no]))
            print("  Actual:\t{}".format(actual))
            sys.exit(1)


    def _run(self):
        """Does the actual work of running the tested app. Called by test method
        and returns the exit code of app and anything in STDOUT.
        """
        with subprocess.Popen(
                self._app, stderr=subprocess.PIPE,
                stdin=subprocess.PIPE, stdout=subprocess.PIPE) as proc:
            out, _ = proc.communicate(
                input=self._input[self._test_no].encode("utf-8"))

            try:
                return proc.returncode, out.decode("utf-8") if out else None
            except UnicodeDecodeError as decode_exception:
                return proc.returncode, \
                       "Serious execution badness: {}".format(decode_exception)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("USAGE: test_parse_grades.py [1 | 2] to run tests 1 or 2")
    else:
        TestDecomposer(int(sys.argv[1]) - 1)
   
